#include <windows.h>
#include <cocos2d.h>
#include <gd.h>
#include "hitboxnode.hpp"
using namespace cocos2d;

class TrajectorySimulation
{
public:
	gd::PlayerObject* m_pPlayer1ForSimulation = nullptr;
	gd::PlayerObject* m_pPlayer2ForSimulation = nullptr;
	bool m_pIsSimulation = false;
	bool m_pDieInSimulation = false;
	CCActionInterval* rotateAction;

	void createPlayersForSimulation();
	void createSimulation();
	void simulationPerPlayer(gd::PlayerObject* player, gd::PlayerObject* playerBase, float dt);
	void processMainSimulation(float dt);
	bool shouldInterrumpHooksWithPlayer(gd::PlayerObject* player);
	void activateObjectsOnPlayerSimulations(gd::GameObject* obj, gd::PlayerObject* player);
	bool shouldInterrumpHooks();
	static TrajectorySimulation* getInstance();
	void onQuitPlayLayer();
};