#pragma once 

#include "Scene.hpp"


#include "engine/Entity.hpp"

#include "engine/Shader.hpp"
#include "components/SkyBox.hpp"

#include "physics/PhysicsWorld.hpp"

namespace lei3d {
    class Entity;
    class Model;
    class Shader;
    class SkyBox;

    class TestScene : public Scene {
    private:
        PhysicsWorld m_PhysicsWorld;
    public:
        TestScene();
        ~TestScene();

        void LoadObjects() override;
        void OnUpdate(float deltaTime) override;
        void OnPhysicsUpdate(float deltaTime) override;
        void OnRender() override;
    };
}