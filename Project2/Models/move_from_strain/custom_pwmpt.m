function pt=custom_pwmpt
pt = [];

  
pt(1).blockname = 'Amplitude';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'custom_pwm_P.Amplitude_Value';
pt(1).baseaddr   = '&custom_pwm_P.Amplitude_Value';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'PD';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'custom_pwm_P.PD_Value';
pt(2).baseaddr   = '&custom_pwm_P.PD_Value';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'PW';
pt(3).paramname = 'Value';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'custom_pwm_P.PW_Value';
pt(3).baseaddr   = '&custom_pwm_P.PW_Value';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'Period';
pt(4).paramname = 'Value';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'custom_pwm_P.Period_Value';
pt(4).baseaddr   = '&custom_pwm_P.Period_Value';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'Programmable Pulse Generator/Constant';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'custom_pwm_P.Constant_Value';
pt(5).baseaddr   = '&custom_pwm_P.Constant_Value';
pt(5).dtname     = 'real_T';



  
pt(6).blockname = 'Programmable Pulse Generator/Constant1';
pt(6).paramname = 'Value';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'custom_pwm_P.Constant1_Value';
pt(6).baseaddr   = '&custom_pwm_P.Constant1_Value';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'Programmable Pulse Generator/Phase Delay Switch';
pt(7).paramname = 'Threshold';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'custom_pwm_P.PhaseDelaySwitch_Threshold';
pt(7).baseaddr   = '&custom_pwm_P.PhaseDelaySwitch_Threshold';
pt(7).dtname     = 'real_T';


function len = getlenPT
len = 7;

