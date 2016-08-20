uniform vec3 FlashEvent;
//in vec2 fragCoord;
void main()
{
	//for(int i = 0;i < 5;++i)
	//{
	if(FlashEvent.z >= 0){
		//fragCoord = fragCoord;
		vec2 dist = gl_FragCoord - vec2(1,1);//FlashEvent.xy;
		float intensity = (sqrt(dot(dist,dist)));
		float Changeover = 3.0;
		if(FlashEvent.z < Changeover)
		{
			intensity = (intensity * 1.0) / (80*FlashEvent.z);
			intensity = min(intensity,1.0);
		}
		else
		{
			float Temptime = FlashEvent.z - Changeover;
			intensity = (0.05 * Temptime * Temptime);
			intensity = min(intensity,1.0);
		}
		intensity = 1.0 - intensity;
		gl_FragColor = vec4(1,1,1,intensity);
	}
	else{
		gl_FragColor = vec4(1,1,1,0);
	}
}