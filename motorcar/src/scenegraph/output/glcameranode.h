#ifndef GLCAMERANODE_H
#define GLCAMERANODE_H
#include "../../geometry.h"
#include "../virtualnode.h"
#include "outputelement.h"
#include <GL/gl.h>
//#include "display.h"



namespace motorcar {
class Display;
class GLCamera : public OutputElement, public VirtualNode
{
public:
    //centerOfProjection: center of projection in camera space, applied as a translation to the projection matrix
    GLCamera(SceneGraphNode &parent, glm::mat4 transform, float near, float far, Display *display, glm::vec3 centerOfProjection = glm::vec3(0));
    Geometry::Ray worldRayAtDisplayPosition(float pixelX, float pixelY);

    void calculateVPMatrix();
    glm::mat4 viewMatrix() const;
    glm::mat4 projectionMatrix() const;
    glm::mat4 viewProjectionMatrix() const;

    //returns camera vertical field of view in degrees
    float fov();


    //normalized viewport within a given window,
    //all numerical arguments range from 0 to 1 and are multiplied by the size of the window in all getters and before being passed to OpenGL calls
    class GLViewPort{
    public:

        GLViewPort(float offsetX, float offsetY, float width, float height, Display *display);

        float offsetX() const;
        float offsetY() const;
        float width() const;
        float height() const;

        //calls glViewport with parameters
        void set() const;

        //
        glm::vec2 displayCoordsToViewportCoords(float pixelX, float pixelY) const;


        Display *display() const;
        void setDisplay(Display *display);

    private:
        float m_offsetX, m_offsetY, m_width, m_height;
        Display *m_display;
    };



    GLViewPort *viewport() const;
    void setViewport(GLViewPort *viewport);

private:
    float near, far;
    glm::mat4 m_COPTransform;
    GLViewPort *m_viewport;
    glm::mat4 m_viewMatrix, m_projectionMatrix, m_viewProjectionMatrix;

};
}



#endif // GLCAMERANODE_H
