#include "MeshRenderer.h"


const char* src =
	"#ifdef VERTEX                                 \n" \
	"                                              \n" \
	"attribute vec3 a_Position;                    \n" \
	"attribute vec2 a_TexCoord;                    \n" \
	"attribute vec3 a_Normal;                      \n" \
	"                                              \n" \
	"uniform mat4 u_Projection;                    \n" \
	"uniform mat4 u_Model;                         \n" \
	"                                              \n" \
	"varying vec3 v_Normal;                        \n" \
	"varying vec2 v_TexCoord;                      \n" \
	"                                              \n" \
	"void main()                                   \n" \
	"{                                             \n" \
	"  gl_Position = u_Projection *                \n" \
	"    u_Model * vec4(a_Position, 1);            \n" \
	"                                              \n" \
	"  v_Normal = a_Normal;                        \n" \
	"  v_TexCoord = a_TexCoord;                    \n" \
	"}                                             \n" \
	"                                              \n" \
	"#endif                                        \n" \
	"#ifdef FRAGMENT                               \n" \
	"                                              \n" \
	"varying vec3 v_Normal;                        \n" \
	"varying vec2 v_TexCoord;                      \n" \
	"                                              \n" \
	"void main()                                   \n" \
	"{                                             \n" \
	"  gl_FragColor = vec4(v_TexCoord, 0, 1);      \n" \
	"  gl_FragColor.z = v_Normal.x;                \n" \
	"}                                             \n" \
	"                                              \n" \
	"#endif                                        \n";


void MeshRenderer::OnInitialize()
{
	// ToDo: Fix this exception
	//m_shader = GetCore()->m_context->createShader();
	shared<Core> a = GetCore();
	shared<rend::Context> b = a->m_context;
	m_shader = b->createShader();

	m_shader->parse(src);
}

void MeshRenderer::OnDisplay()
{
	std::cout << "Renderer::onDisplay" << std::endl;
	//shared<Entity> ent = getEntity()->getCore()->addEntity();
}

