#pragma once
#include <memory>
#include<list>
#include "../Common/ImageCtl.h"
#include "../Common/Vector2D.h"
#include "../Actor/ActorType.h"

class  BaseScene;
class Actor;


using sharedActor = std::shared_ptr<Actor>;
using ActorList = std::list<sharedActor>;

class Actor
{
public:
	Actor();
	Actor(ActorType type, Vector2D pos);
	 ~Actor();
	virtual void Update(BaseScene& scene)=0;	//所有権を持たない
	void Draw(const Vector2D& camOffset);
	ActorType GetActorType(void) { return type_; }


private:
	Vector2D circle;
	int circle_r_=5;


protected:
	Vector2D pos_;
	int speed_;		//移動量
	ActorType type_;
	friend class GameScene;
};

