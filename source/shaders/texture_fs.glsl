varying vec2 tex;
varying vec3 colour;
uniform sampler2D texture0;

void main(void)
{
	gl_FragColor = texture2D(texture0, tex) * vec4(colour, 1.0);
}
