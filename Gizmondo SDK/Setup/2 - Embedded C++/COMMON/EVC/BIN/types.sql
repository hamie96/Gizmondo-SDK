INSERT INTO   DataType VALUES ('1','Number','Numeric data. Includes booleans' )
INSERT INTO   DataType VALUES ('2','String','Character data' )
INSERT INTO   DataType VALUES ('3','GUID','GUID' )

INSERT INTO   ProjectType VALUES ('1','application',NULL )
INSERT INTO   ProjectType VALUES ('2','dll',NULL )
INSERT INTO   ProjectType VALUES ('3','console',NULL )
INSERT INTO   ProjectType VALUES ('4','lib',NULL )
INSERT INTO   ProjectType VALUES ('14','OS Builder',NULL )
INSERT INTO   ProjectType VALUES ('6','External Target',NULL )

INSERT INTO OptionSetType VALUES ('16777216','EXEREL','Application','1')    
INSERT INTO OptionSetType VALUES ('16777232','MFCEXEREL','MFC Application','1')           
INSERT INTO OptionSetType VALUES ('16777472','EXEDBG','Application','1')    
INSERT INTO OptionSetType VALUES ('16777488','MFCEXEDBG','MFC Application','1')           
INSERT INTO OptionSetType VALUES ('16777217','ATLEXERELMINSIZE','ATL','1')     
INSERT INTO OptionSetType VALUES ('16777218','ATLEXERELMINDEP','ATL','1')
INSERT INTO OptionSetType VALUES ('16777473','ATLEXEDBG','ATL','1')                  
INSERT INTO OptionSetType VALUES ('33554432','DLLREL','Dynamic-Link Library','2')         
INSERT INTO OptionSetType VALUES ('33554433','ATLRELMINSIZE','ATL','2')     
INSERT INTO OptionSetType VALUES ('33554434','ATLRELMINDEP','ATL','2')      
INSERT INTO OptionSetType VALUES ('33554448','MFCDLLREL','MFC Dynamic-Link Library','2')  
INSERT INTO OptionSetType VALUES ('33554688','DLLDBG','Dynamic-Link Library','2')         
INSERT INTO OptionSetType VALUES ('33554689','ATLDBG','ATL','2')            
INSERT INTO OptionSetType VALUES ('33554704','MFCDLLDBG','MFC Dynamic-Link Library','2')  
INSERT INTO OptionSetType VALUES ('33558544','ACTIVEXCONTROLREL','MFC ActiveX Control','2')             
INSERT INTO OptionSetType VALUES ('33558800','ACTIVEXCONTROLDBG','MFC ActiveX Control','2')             
INSERT INTO OptionSetType VALUES ('50331648','CONREL','Console Application','3')          
INSERT INTO OptionSetType VALUES ('50331904','CONDBG','Console Application','3')          
INSERT INTO OptionSetType VALUES ('67108864','LIBREL','static library','4') 
INSERT INTO OptionSetType VALUES ('67109120','LIBDBG','static library','4') 

INSERT INTO   OptionType VALUES ('1','supported',NULL )
INSERT INTO   OptionType VALUES ('0','unsupported','This option is NOT supported for this tool' )
INSERT INTO   OptionType VALUES ('1000','ASSEMBLY_LISTING','assembly listing' )
INSERT INTO   OptionType VALUES ('1001','DISABLE_CONSTRUCTION_DISPLACEMENT','Project Setting->C++ Language' )
INSERT INTO   OptionType VALUES ('1002','GENERAL_PURPOSE_ALWAYS','Project Setting->C++ Language' )
INSERT INTO   OptionType VALUES ('1003','PRECOMPILE_HEADER','Precompile header support' )
INSERT INTO   OptionType VALUES ('1004','LINKDBG_FORMAT_COFF','Debugger data format COFF' )
INSERT INTO   OptionType VALUES ('1005','FRAME_POINTER_OMISSION','Frame Pointer Omission optimization.' )
INSERT INTO   OptionType VALUES ('1006','INCREMENTAL_LINKING','Supports Incremental Linking.' )
INSERT INTO   OptionType VALUES ('1007','ASSUME_NO_ALIASING','Supports Assume No Aliasing.')

INSERT INTO   DisplayType VALUES ('1','Hidden','Don''t display to user' )
INSERT INTO   DisplayType VALUES ('2','Normal','Default display' )

INSERT INTO   ToolType VALUES ('1','CPP_COMPILER','Complies C and C++ source to .obj' )
INSERT INTO   ToolType VALUES ('2','DEBUGGER','Symbolic debugger' )
INSERT INTO   ToolType VALUES ('3','RES_COMPILER','Compiles .rc source to .res' )
INSERT INTO   ToolType VALUES ('4','LINKER','Links .exe, .dll' )
INSERT INTO   ToolType VALUES ('5','LIB','library manager' )
INSERT INTO   ToolType VALUES ('6','CEF_DEBUGGER','The real debugger for CEF' )
INSERT INTO   ToolType VALUES ('7','MIDL_COMPILER','Middle compiler' )
INSERT INTO   ToolType VALUES ('8','BS32_CPMPILER','Browser compiler' )
INSERT INTO   ToolType VALUES ('9','COFF','Coff' )
INSERT INTO   ToolType VALUES ('10','CEF_TRANSLATOR','CEF Translator' )

