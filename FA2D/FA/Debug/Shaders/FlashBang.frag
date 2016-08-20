
uniform vec3 FlashEvent;
in vec2 fragCoord;
void main()
{
	//for(int i = 0;i < 5;++i)
	//{
		if(FlashEvent.z > 0){
			//fragCoord = fragCoord;
			vec2 dist = fragCoord - FlashEvent.xy;
			float intensity = (sqrt(dot(dist,dist)));
			if(FlashEvent.z < 2.0)
			{
				intensity = (intensity * 5.0) / (100.0*FlashEvent.z);
			}
			else
			{
				float Temptime = FlashEvent.z - 2.0;
				intensity = (0.05 *Temptime*Temptime);
				intensity = min(intensity,1.0);
			}
			intensity = 1.0 - intensity;
			gl_FragColor = vec4(intensity,intensity,intensity,1);
		}
	else{
		gl_FragColor = vec4(1,1,1,0);
	}
}