#include "GuiComponent.hpp"

#include "rendering/gui/GuiManager.hpp"

namespace lei3d
{
	unsigned GuiComponent::s_nextId = 0;

	const glm::vec3 GuiComponent::s_anchorPositions[unsigned(Anchor::ANCHOR_COUNT)] = 
	{
		{0.0f, 1.0f, 0},	// TOP_LEFT
		{1.0f, 1.0f, 0},	// TOP_RIGHT
		{0.0f, 0.0f, 0},	// BOTTOM_LEFT
		{1.0f, 0.0f, 0},	// BOTTOM_RIGHT
		{0.5f, 1.0f, 0},	// CENTER_TOP
		{1.0f, 0.5f, 0},	// CENTER_RIGHT
		{0.5f, 0.0f, 0},	// CENTER_BOTTOM
		{0.0f, 0.5f, 0},	// CENTER_LEFT
		{0.5f, 0.5f, 0}	// CENTER
	};

	GuiComponent::GuiComponent(Anchor anchor, const std::pair<Space, glm::vec2>& pos, const std::pair<Space, glm::vec2>& size)
		: m_anchor((unsigned)anchor)
		, m_position(pos)
		, m_size(size)
	{
		m_id = s_nextId++;
		GuiManager::Instance().AddGuiComponent(this);
	}

	GuiComponent::~GuiComponent()
	{
		GuiManager::Instance().RemoveGuiComponent(m_id);
	}

	void GuiComponent::SetPositionNormalized(const glm::vec2& pos)
	{
		m_position = { Space::NORMALIZED, pos };
	}

	void GuiComponent::SetPositionPixels(const glm::vec2& pos)
	{
		m_position = { Space::PIXELS, pos };
	}

	void GuiComponent::SetSizeNormalized(const glm::vec2& size)
	{
		m_size = { Space::NORMALIZED, size };
	}

	void GuiComponent::SetSizePixels(const glm::vec2& size)
	{
		m_size = { Space::PIXELS, size };
	}

	void GuiComponent::BeginRender()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_DEPTH_TEST);
	}

	void GuiComponent::EndRender()
	{
		glDisable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ZERO);
		glEnable(GL_DEPTH_TEST);
	}

	glm::vec3 GuiComponent::PosNormalized(const glm::vec2& screenSize)
	{
		glm::vec3 pos = s_anchorPositions[m_anchor];

		if (m_position.first == Space::PIXELS)
		{
			pos += glm::vec3(m_position.second / screenSize, 0);
		}
		else
		{
			pos += glm::vec3(m_position.second, 0);
		}

		return pos;
	}

	glm::vec2 GuiComponent::SizeNormalized(const glm::vec2& screenSize)
	{
		if (m_size.first == Space::PIXELS)
		{
			return m_size.second / screenSize;
		}
		else
		{
			return m_size.second;
		}
	}
}
