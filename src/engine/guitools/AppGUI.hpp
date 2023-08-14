#pragma once

#include "core/Application.hpp"

#include <imgui.h>

namespace lei3d
{
	class Application;
	class Scene;

	class AppGUI
	{
	private:
		bool m_ShowDemoWindow = false;

	public:
		void RenderUI();	//DON"T MAKE THIS CONST
	};
} // namespace lei3d