// Logo.pov - Bubbles logo source (POV-Ray)
//
// The Bubbles logo was designed with a raytracer program called
// POV-Ray. POV-Ray is a copyrighted freeware program to create
// stunning images (this is just a lousy experiment) and can be
// obtained from:
//
//  http://www.povray.org
//
// You can re-render the bitmap using POV-Ray with a picture
// setting 240x294 pixels with an anti-alias setting of 0.1.


global_settings { assumed_gamma 1.3 }

// Include files
#include "colors.inc"
#include "textures.inc"
#include "tetramino.inc"


// Camera position

camera 
{
  location  <     -3, 2.3,-10  >
  direction <      0,   0,  1.5>
  sky       <      0,   1,  0  >
  right     <240/294,   0,  0  >
  look_at   <      0,   2,  0  >
}


// Light positions

object { light_source { < 10, 10, -25> color White } }

// Cloudy sky

object 
{
  sphere { -39000*y, 40000 inverse }
  pigment 
  {
    bozo
    colour_map
    {
      [0.5, color rgb <0.4, 0.5, 1.0> ]
      [0.7, color rgb <0.8, 0.8, 0.8> ]
      [1.0, color rgb <0.7, 0.7, 0.7> ]
    }
    turbulence 0.5
    scale 2000
  }
  finish { ambient 1 diffuse 0 }
  no_shadow
}


// Wooden floor

object 
{ 
  plane { y, -0.5 }
  texture 
  { 
    pigment { Tan_Wood }
    scale <0.2 0.2 0.2>
    rotate <3 45 10>
  }
}


// Place of the shapes

object { Tetramino_L rotate <0, 0,   0> translate <-2, 0, 0> }
object { Tetramino_T rotate <0, 0,   0> translate <-1, 0, 0> }
object { Tetramino_J rotate <0, 0,   0> translate < 1, 0, 0> }
object { Tetramino_S rotate <0, 0,   0> translate < 0, 2, 0> }
/*


object { Tetramino_I rotate <0, 0,  90> translate <-2, 0, 0> }
object { Tetramino_Z rotate <0, 0,  90> translate < 0, 1, 0> }
object { Tetramino_S rotate <0, 0,  90> translate < 2, 0, 0> }
object { Tetramino_T rotate <0, 0,   0> translate <-2, 3, 0> }
*/