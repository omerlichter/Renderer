cmake_minimum_required(VERSION 3.8)
project(Renderer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pixel.h WriteBMP.cpp WriteBMP.h Renderer.cpp Renderer.h Listener.h RenderLog.cpp RenderLog.h Notifier.h Vector.cpp Vector.h Camera.cpp Camera.h Ray.cpp Ray.h Scene.cpp Scene.h Object.h Sphere.cpp Sphere.h RayCastHit.cpp RayCastHit.h Collidable.h DirectionalLight.cpp DirectionalLight.h Materialize.h Color.cpp Color.h Material.h DiffuseMat.cpp DiffuseMat.h DiffuseSpecularMat.cpp DiffuseSpecularMat.h)
add_executable(Renderer ${SOURCE_FILES})