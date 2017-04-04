varying vec3 colour;

void main(void)
{
  gl_FragColor[0] = colour[0];
  gl_FragColor[1] = colour[1];
  gl_FragColor[2] = colour[2];
}