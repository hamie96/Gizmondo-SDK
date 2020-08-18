#ifndef COLOUR_HSV
#define COLOUR_HSV

// Psuedocode courtesy of easyrgb.com

void rgb2hsv(double R, double G, double B, double * H, double * S, double * V)
{
	double min,max,delta;
	R /= 255; //RGB values = From 0 to 255
	G /= 255;
	B /= 255;

	min = (R<G) ? R : G;
	min = (min<B) ? min : B;

	max = (R>G) ? R : G;
	max = (max>B) ? max : B;
	
	delta = max-min;

	*V = max;

	if ( delta <= 0.0001 )//This is a gray, no chroma...
	{
		*H = 0.0;  //HSV results = From 0 to 1
		*S = 0.0;
	}
	else//Chromatic data...
	{
		double del_R,del_G,del_B;

		*S = delta / max;

		del_R = ( ( ( max - R ) / 6.0 ) + ( delta / 2.0 ) ) / delta;
		del_G = ( ( ( max - G ) / 6.0 ) + ( delta / 2.0 ) ) / delta;
		del_B = ( ( ( max - B ) / 6.0 ) + ( delta / 2.0 ) ) / delta;

		if ( R == max ) *H = del_B - del_G;
		else if ( G == max ) *H = ( 1.0 / 3.0 ) + del_R - del_B;
		else if ( B == max ) *H = ( 2.0 / 3.0 ) + del_G - del_R;

		if ( *H < 0.0 ) *H += 1.0;
		if ( *H > 1.0 ) *H -= 1.0;
	}
}

void hsv2rgb(double H, double S, double V, double * R, double * G, double * B)
{
	if ( S <= 0.0001 )  //HSV values = From 0 to 1
	{
		*R = V * 255; //RGB results = From 0 to 255
		*G = V * 255;
		*B = V * 255;
	}
	else
	{
		double var_h = H * 6.0;
		double var_i = (int)var_h; //Or ... var_i = floor( var_h )
		double var_1 = V * ( 1.0 - S );
		double var_2 = V * ( 1.0 - S * ( var_h - var_i ) );
		double var_3 = V * ( 1.0 - S * ( 1.0 - ( var_h - var_i ) ) );

		double var_r,var_g,var_b;
		if ( var_i == 0 ) { var_r = V; var_g = var_3 ; var_b = var_1; }
		else if ( var_i == 1 ) { var_r = var_2 ; var_g = V  ; var_b = var_1; }
		else if ( var_i == 2 ) { var_r = var_1 ; var_g = V  ; var_b = var_3; }
		else if ( var_i == 3 ) { var_r = var_1 ; var_g = var_2 ; var_b = V;  }
		else if ( var_i == 4 ) { var_r = var_3 ; var_g = var_1 ; var_b = V;  }
		else { var_r = V  ; var_g = var_1 ; var_b = var_2; }

		*R = var_r * 255; //RGB results = From 0 to 255
		*G = var_g * 255;
		*B = var_b * 255;
	}
}

#endif
