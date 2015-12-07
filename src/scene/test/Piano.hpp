
#pragma once
#include "../../object/Object.hpp"
#include "../../device/Device.hpp"
#include "cinder/app/AppNative.h"
#include "../../resource/ResourceManager.hpp"


class Piano: public Object {
private:
public:
	Piano();

	void setup();
	void update();
	void draw();
void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
