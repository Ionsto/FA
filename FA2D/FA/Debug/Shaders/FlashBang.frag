uniform float Time;
uniform vec2 Flash;
in vec2 fragCoord;
void main()
{
	gl_Color
	if(Time > 0){
		fragCoord = fragCoord;
		vec2 Center = vec2(-1.0,-1.0);
		vec2 dist = fragCoord - Center;
		float intensity = (sqrt(dot(dist,dist)));
		if(Time < 2.0)
		{
			intensity = (intensity * 5.0) / (100.0*Time);
		}
		else
		{
			float Temptime = Time - 2.0;
			intensity = (0.05 *Temptime*Temptime);
			intensity = min(intensity,1.0);
		}
		intensity = 1.0 - intensity;
		gl_FragColor = vec4(intensity,intensity,intensity,1);
	}
    gl_FragColor = vec4(1,1,1,1);
}