attribute vec3 coord3d;
attribute vec2 texcoord;
attribute vec3 colour_rgb;
varying vec2 tex;
varying vec3 colour;
uniform mat4 transform;

void main(void)
{
	gl_Position = transform * vec4(coord3d, 1.0);
	colour = colour_rgb;
	tex = texcoord;
}