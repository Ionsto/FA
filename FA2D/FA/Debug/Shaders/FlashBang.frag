uniform vec3 FlashEventA;
uniform vec3 FlashEventB;
uniform vec3 FlashEventC;
//in vec2 fragCoord;
void Flash(vec3 point){
	if(point.z >= 0){
		//fragCoord = fragCoord;
		vec2 dist = gl_FragCoord.xy - point.xy;
		float intensity = length(dist);
		float Changeover = 2.0;
		if(point.z < Changeover)
		{
			intensity = (intensity * 1.0) / (80*point.z);
			intensity = min(intensity,1.0);
		}
		else
		{
			float Temptime = point.z - Changeover;
			intensity = (0.01 * Temptime * Temptime);
			intensity = min(intensity,1.0);
		}
		intensity = 1.0 - intensity;
		gl_FragColor += vec4(1,1,1,intensity);
	}
	else{
		gl_FragColor += vec4(1,1,1,0);
	}
}
void main()
{
	Flash(FlashEventA);
	Flash(FlashEventB);
	Flash(FlashEventC);
}