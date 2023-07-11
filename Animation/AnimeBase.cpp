#include "AnimeBase.h"

AnimeBase::AnimeBase() {
	btnBack = new Button(Vector2f(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT - 40), { 40,40 }, "<<", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnPlay = new Button(btnBack->pos + Vector2f(btnBack->size.x + 10, 0), btnBack->size, "=", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnPlay->SecondText = ">";
	btnForw = new Button(btnPlay->pos + Vector2f(btnBack->size.x + 10, 0), btnBack->size, ">>", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnStart = new Button(btnBack->pos - Vector2f(btnBack->size.x + 10, 0), btnBack->size, "[<<", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);
	btnEnd = new Button(btnForw->pos + Vector2f(btnBack->size.x + 10, 0), btnBack->size, ">>]", black, black + Color(50, 50, 50), black, Color::Transparent, Middle);

	PushToObject(btnBack, this);
	PushToObject(btnForw, this);
	PushToObject(btnPlay, this);
	PushToObject(btnStart, this);
	PushToObject(btnEnd, this);
}

AnimeBase::~AnimeBase()
{
	cleanUp();
}

void AnimeBase::ChooseFrame(int i)
{
	curFrame += i;
	curFrame = min((int)AnimeFrameNode.size(), max(0, curFrame));
	isPlaying = 0;
	transProgress = 0;
	timeCnt = sf::seconds(0.f);
	isHavingAnime = (curFrame < (int)AnimeFrameNode.size()) ? 1 : 0;
}

//drawin'
void AnimeBase::drawFrame(RenderTarget& target, int id) const
{
	if (id > -1 && AnimeFrameNode.size() > id)
	{
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			if (AnimeLinkMatrix[id][i][j] != nullptr)
				target.draw(*AnimeLinkMatrix[id][i][j]);

		for (auto a : AnimeFrameNode[id]) target.draw(*a);
	}
	//cout << "adu " << endl;
}

void AnimeBase::drawTrans(RenderTarget& target) const
{
	for (auto a : TransitionLink) target.draw(*a);

	for (auto a : TransitionNode) target.draw(*a);
}

//create a an empty frame
void AnimeBase::MakeNewFrame()
{
	vector<TreeNode*> tmp{};
	AnimeFrameNode.push_back(tmp);

	vector<vector<Edge*>> pmt{};
	AnimeLinkMatrix.push_back(pmt);

	for (int i = 0; i < n; i++)
	{
		vector<Edge*> vvv;
		AnimeLinkMatrix.back().push_back(vvv);

		for (int j = 0; j < n; j++)
			AnimeLinkMatrix.back().back().push_back(NULL);
	}
}

//create a display_node copy of the tree before change

void AnimeBase::drawCurrent(RenderTarget& target, RenderStates states) const
{
	if (!isHavingAnime || curFrame >= AnimeFrameNode.size()) return;

	if (!isPlaying) drawFrame(target, curFrame);
	else drawTrans(target);
}

void AnimeBase::updateCurrent(Event& event, Vector2f& MousePos)
{
	if (btnBack->isPressed()) ChooseFrame(-1); else if (btnForw->isPressed()) ChooseFrame(1);
	if (btnPlay->isPressed()) isPlaying = isPlaying ? 0 : 1;
	if (btnStart->isPressed()) ChooseFrame(-100); else if (btnEnd->isPressed()) ChooseFrame(100);
	if (isPlaying) btnPlay->ForceOn(); else btnPlay->ForceOff();
}

void AnimeBase::takeTimeCurrent(Time& dt)
{
	isHavingAnime = (curFrame < (int)AnimeFrameNode.size()) ? 1 : 0;

	if (!isHavingAnime) isPlaying = 0;

	if (!isPlaying) return;

	makeTransition();

	timeCnt += dt;

	if (timeCnt >= TIME_PER_ANIME_FRAME) curFrame = min((int)AnimeFrameNode.size(), curFrame + 1), timeCnt -= TIME_PER_ANIME_FRAME;

	transProgress = timeCnt / TIME_PER_ANIME_FRAME;
}

// the Transition

void AnimeBase::makeTransition()
{
	if (!isPlaying || curFrame > AnimeFrameNode.size()) return;

	for (auto a : TransitionNode) delete a;
	for (auto a : TransitionLink) delete a;

	TransitionNode.clear();
	TransitionLink.clear();

	int u = curFrame;
	int v = min(curFrame + 1, (int)AnimeFrameNode.size() - 1);

	for (int i = 0; i < n; i++)	TransitionNode.push_back(InterpolateNode(AnimeFrameNode[u][i], AnimeFrameNode[v][i], transProgress));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			Edge* a = AnimeLinkMatrix[u][i][j] ? AnimeLinkMatrix[u][i][j] : AnimeLinkMatrix[u][j][i];
			Edge* b = AnimeLinkMatrix[v][i][j] ? AnimeLinkMatrix[v][i][j] : AnimeLinkMatrix[v][j][i];

			TransitionLink.push_back(InterpolateEdge(a, b, transProgress));
		}
	}
}

TreeNode* AnimeBase::InterpolateNode(TreeNode* a, TreeNode* b, float t)
{
	TreeNode* res = new TreeNode(noType, "", 0);

	res->Cir = a->Cir;
	res->text = a->text;

	int r_diff = b->Cir.getOutlineColor().r - a->Cir.getOutlineColor().r;
	int g_diff = b->Cir.getOutlineColor().g - a->Cir.getOutlineColor().g;
	int b_diff = b->Cir.getOutlineColor().b - a->Cir.getOutlineColor().b;

	int red = a->Cir.getOutlineColor().r + t * r_diff;
	int green = a->Cir.getOutlineColor().g + t * g_diff;
	int blue = a->Cir.getOutlineColor().b + t * b_diff;
	int alpha = 255;


	if (b->isDisable)
	{
		if (a->isDisable) res->Disable();
		else alpha = 255 - (255 * t);
	}
	else if (a->isDisable) alpha = 0 + 255 * t;

	res->Cir.setOutlineColor(Color(red, green, blue, alpha));

	res->Cir.setPosition((1 - t) * a->Cir.getPosition() + t * b->Cir.getPosition());
	res->text.setPosition(res->Cir.getPosition().x - res->text.getGlobalBounds().width / 2.f, res->Cir.getPosition().y - res->text.getGlobalBounds().height / 2.f);

	return res;
}

Edge* AnimeBase::InterpolateEdge(Edge* a, Edge* b, float t)
{
	Edge* res = new Edge(noType, "", 0);

	int alpha = 255;

	if (!b)
	{
		if (!a) res->Disable();
		else
		{
			res->line = a->line;

			int r_diff = 255 - a->line.getFillColor().r;
			int g_diff = 255 - a->line.getFillColor().g;
			int b_diff = 255 - a->line.getFillColor().b;

			int red = a->line.getFillColor().r + t * r_diff;
			int green = a->line.getFillColor().g + t * g_diff;
			int blue = a->line.getFillColor().b + t * b_diff;

			alpha = 255 - (255 * t);

			res->line.setFillColor(Color(red, green, blue, alpha));
			res->setPositionByNode(a->pos1, a->pos2);
		}
	}
	else
	{
		if (!a)
		{
			int r_diff = b->line.getFillColor().r - 255;
			int g_diff = b->line.getFillColor().g - 255;
			int b_diff = b->line.getFillColor().b - 255;

			int red = 255 + t * r_diff;
			int green = 255 + t * g_diff;
			int blue = 255 + t * b_diff;

			alpha = 0 + 255 * t;

			res->line.setFillColor(Color(red, green, blue, alpha));
			res->setPositionByNode(b->pos1, b->pos2);
		}
		else
		{
			int r_diff = b->line.getFillColor().r - a->line.getFillColor().r;
			int g_diff = b->line.getFillColor().g - a->line.getFillColor().g;
			int b_diff = b->line.getFillColor().b - a->line.getFillColor().b;

			int red = a->line.getFillColor().r + t * r_diff;
			int green = a->line.getFillColor().g + t * g_diff;
			int blue = a->line.getFillColor().b + t * b_diff;
			alpha = 255;

			res->line.setFillColor(Color(red, green, blue, alpha));

			Vector2f pos1Diff = b->pos1 - a->pos1;
			Vector2f pos2Diff = b->pos2 - a->pos2;

			res->setPositionByNode(Vector2f(a->pos1.x + pos1Diff.x * t, a->pos1.y + pos1Diff.y * t), Vector2f(a->pos2.x + pos2Diff.x * t, a->pos2.y + pos2Diff.y * t));
		}
	}

	return res;
}

// misc

void AnimeBase::CloneLastFrame()
{
	MakeNewFrame();

	for (auto a : AnimeFrameNode[AnimeFrameNode.size() - 2])
	{
		TreeNode* tmp = new TreeNode(noType, "", 0);
		tmp->Cir = a->Cir;
		tmp->text = a->text;
		tmp->isDisable = a->isDisable;
		tmp->data = a->data;

		AnimeFrameNode.back().push_back(tmp);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			Edge* tmp = nullptr;
			if (AnimeLinkMatrix[AnimeLinkMatrix.size() - 2][i][j] != nullptr)
			{
				auto a = AnimeLinkMatrix[AnimeLinkMatrix.size() - 2][i][j];
				tmp = new Edge(noType, "", 0);

				tmp->line = a->line;
				tmp->text = a->text;
				tmp->isDisable = a->isDisable;

				tmp->pos1 = a->pos1;
				tmp->pos2 = a->pos2;
			}

			AnimeLinkMatrix.back()[i][j] = tmp;
		}
}