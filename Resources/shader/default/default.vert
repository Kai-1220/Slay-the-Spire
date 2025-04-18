#version 130

in vec2 a_position;
in vec4 a_color;
in vec2 a_texCoord0;

uniform mat4 u_projTrans;

out vec4 v_color;
out vec2 v_texCoords;

void main()
{
   gl_Position =  u_projTrans * vec4(a_position, 0, 1.0);//I have no idea why this needs to be drawn first. The only thing I know is that if it's not done first, bugs occur.
   v_color = a_color;
   v_color.a = v_color.a * (255.0/254.0);
   v_texCoords = a_texCoord0;
}