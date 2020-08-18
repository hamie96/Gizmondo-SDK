#declare Tetramino_Blue      = texture { finish { phong 0.5 } pigment { color Blue      } }
#declare Tetramino_Magenta   = texture { finish { phong 0.5 } pigment { color Magenta   } }
#declare Tetramino_Green     = texture { finish { phong 0.5 } pigment { color Green     } }
#declare Tetramino_Gray      = texture { finish { phong 0.5 } pigment { color Gray50    } }
#declare Tetramino_Red       = texture { finish { phong 0.5 } pigment { color Red       } }
#declare Tetramino_Yellow    = texture { finish { phong 0.5 } pigment { color Yellow    } }
#declare Tetramino_Lightblue = texture { finish { phong 0.5 } pigment { color SteelBlue } }


#declare Box = 
  object
  {
    superellipsoid 
    {
      <0.25, 0.25>
      scale <0.5, 0.5, 0.5>
    }
  }

#declare Tetramino_J =
  object                
  {
    union
    {
      object { Box translate <1, 2, 0> }
      object { Box translate <1, 1, 0> }
      object { Box translate <0, 0, 0> }
      object { Box translate <1, 0, 0> }
    }
    texture { Tetramino_Blue }
  }

#declare Tetramino_L =
  object                
  {
    union
    {
      object { Box translate <0, 2, 0> }
      object { Box translate <0, 1, 0> }
      object { Box translate <0, 0, 0> }
      object { Box translate <1, 0, 0> }
    }
    texture { Tetramino_Magenta }
  }

#declare Tetramino_S =
  object
  {                                              
    union { 
      object { Box translate <1, 1, 0> }
      object { Box translate <2, 1, 0> }
      object { Box translate <0, 0, 0> }
      object { Box translate <1, 0, 0> }
    }
    texture { Tetramino_Green }
  }

#declare Tetramino_O =
  object
  {                                              
    union { 
      object { Box translate <0, 0, 0> }
      object { Box translate <1, 0, 0> }
      object { Box translate <0, 1, 0> }
      object { Box translate <1, 1, 0> }
    }
    texture { Tetramino_Gray }
  }

#declare Tetramino_Z =
  object
  {                                              
    union { 
      object { Box translate <0, 1, 0> }
      object { Box translate <1, 1, 0> }
      object { Box translate <1, 0, 0> }
      object { Box translate <2, 0, 0> }
    }
    texture { Tetramino_Red }
  }

#declare Tetramino_T =
  object
  {                                              
    union { 
      object { Box translate <0, 1, 0> }
      object { Box translate <1, 1, 0> }
      object { Box translate <2, 1, 0> }
      object { Box translate <1, 0, 0> }
    }
    texture { Tetramino_Yellow }
  }

#declare Tetramino_I =
  object
  {                                              
    union { 
      object { Box translate <0, 0, 0> }
      object { Box translate <1, 0, 0> }
      object { Box translate <2, 0, 0> }
      object { Box translate <3, 0, 0> }
    }
    texture { Tetramino_Lightblue }
  }
