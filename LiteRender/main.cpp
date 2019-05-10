#include <iostream>
#include "World/World.h"

int main()
{
	World w;
	w.build();
	w.camera_ptr->render_scene(w);

	return 0;
}