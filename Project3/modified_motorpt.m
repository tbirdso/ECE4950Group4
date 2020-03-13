function pt=modified_motorpt
pt = [];

  
pt(1).blockname = 'Run';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'modified_motor_P.Run_Value';
pt(1).baseaddr   = '&modified_motor_P.Run_Value';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'Switch';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'modified_motor_P.Switch_Value';
pt(2).baseaddr   = '&modified_motor_P.Switch_Value';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'Logic Block/Rate Transition';
pt(3).paramname = 'X0';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'modified_motor_P.RateTransition_X0';
pt(3).baseaddr   = '&modified_motor_P.RateTransition_X0';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'UI/Color';
pt(4).paramname = 'Value';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'modified_motor_P.Color_Value';
pt(4).baseaddr   = '&modified_motor_P.Color_Value';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'UI/Mode';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_INT8';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'modified_motor_P.Mode_Value';
pt(5).baseaddr   = '&modified_motor_P.Mode_Value';
pt(5).dtname     = 'int8_T';



  
pt(6).blockname = 'UI/Position';
pt(6).paramname = 'Value';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'modified_motor_P.Position_Value';
pt(6).baseaddr   = '&modified_motor_P.Position_Value';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'motor_subsystem/Gain';
pt(7).paramname = 'Gain';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'modified_motor_P.Gain_Gain';
pt(7).baseaddr   = '&modified_motor_P.Gain_Gain';
pt(7).dtname     = 'real_T';



  
pt(8).blockname = 'motor_subsystem/KI';
pt(8).paramname = 'Gain';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';
pt(8).isStruct  = false;
pt(8).symbol     = 'modified_motor_P.KI_Gain';
pt(8).baseaddr   = '&modified_motor_P.KI_Gain';
pt(8).dtname     = 'real_T';



  
pt(9).blockname = 'motor_subsystem/Kd';
pt(9).paramname = 'Gain';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';
pt(9).isStruct  = false;
pt(9).symbol     = 'modified_motor_P.Kd_Gain';
pt(9).baseaddr   = '&modified_motor_P.Kd_Gain';
pt(9).dtname     = 'real_T';



  
pt(10).blockname = 'motor_subsystem/Kp';
pt(10).paramname = 'Gain';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';
pt(10).isStruct  = false;
pt(10).symbol     = 'modified_motor_P.Kp_Gain';
pt(10).baseaddr   = '&modified_motor_P.Kp_Gain';
pt(10).dtname     = 'real_T';



  
pt(11).blockname = 'motor_subsystem/Integrator';
pt(11).paramname = 'InitialCondition';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';
pt(11).isStruct  = false;
pt(11).symbol     = 'modified_motor_P.Integrator_IC';
pt(11).baseaddr   = '&modified_motor_P.Integrator_IC';
pt(11).dtname     = 'real_T';



  
pt(12).blockname = 'motor_subsystem/Saturation';
pt(12).paramname = 'UpperLimit';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';
pt(12).isStruct  = false;
pt(12).symbol     = 'modified_motor_P.Saturation_UpperSat';
pt(12).baseaddr   = '&modified_motor_P.Saturation_UpperSat';
pt(12).dtname     = 'real_T';



  
pt(13).blockname = 'motor_subsystem/Saturation';
pt(13).paramname = 'LowerLimit';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';
pt(13).isStruct  = false;
pt(13).symbol     = 'modified_motor_P.Saturation_LowerSat';
pt(13).baseaddr   = '&modified_motor_P.Saturation_LowerSat';
pt(13).dtname     = 'real_T';



  
pt(14).blockname = 'Logic Block/Clock/Constant';
pt(14).paramname = 'Value';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';
pt(14).isStruct  = false;
pt(14).symbol     = 'modified_motor_P.Constant_Value_b';
pt(14).baseaddr   = '&modified_motor_P.Constant_Value_b';
pt(14).dtname     = 'real_T';



  
pt(15).blockname = 'Logic Block/Clock/Unit Delay';
pt(15).paramname = 'InitialCondition';
pt(15).class     = 'scalar';
pt(15).nrows     = 1;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';
pt(15).isStruct  = false;
pt(15).symbol     = 'modified_motor_P.UnitDelay_InitialCondition';
pt(15).baseaddr   = '&modified_motor_P.UnitDelay_InitialCondition';
pt(15).dtname     = 'real_T';



  
pt(16).blockname = 'Logic Block/Position Iterator/Target_Position';
pt(16).paramname = 'InitialOutput';
pt(16).class     = 'scalar';
pt(16).nrows     = 1;
pt(16).ncols     = 1;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';
pt(16).isStruct  = false;
pt(16).symbol     = 'modified_motor_P.Target_Position_Y0';
pt(16).baseaddr   = '&modified_motor_P.Target_Position_Y0';
pt(16).dtname     = 'real_T';



  
pt(17).blockname = 'Logic Block/Position Iterator/Target_Position1';
pt(17).paramname = 'InitialOutput';
pt(17).class     = 'scalar';
pt(17).nrows     = 1;
pt(17).ncols     = 1;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';
pt(17).isStruct  = false;
pt(17).symbol     = 'modified_motor_P.Target_Position1_Y0';
pt(17).baseaddr   = '&modified_motor_P.Target_Position1_Y0';
pt(17).dtname     = 'real_T';



  
pt(18).blockname = 'Logic Block/Position Iterator/Target_Position2';
pt(18).paramname = 'InitialOutput';
pt(18).class     = 'scalar';
pt(18).nrows     = 1;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';
pt(18).isStruct  = false;
pt(18).symbol     = 'modified_motor_P.Target_Position2_Y0';
pt(18).baseaddr   = '&modified_motor_P.Target_Position2_Y0';
pt(18).dtname     = 'real_T';



  
pt(19).blockname = 'Logic Block/Position Iterator/Store_Index';
pt(19).paramname = 'InitialValue';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';
pt(19).isStruct  = false;
pt(19).symbol     = 'modified_motor_P.Store_Index_InitialValue';
pt(19).baseaddr   = '&modified_motor_P.Store_Index_InitialValue';
pt(19).dtname     = 'real_T';



  
pt(20).blockname = 'Logic Block/Position Iterator/Store_run_pulse';
pt(20).paramname = 'InitialValue';
pt(20).class     = 'scalar';
pt(20).nrows     = 1;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';
pt(20).isStruct  = false;
pt(20).symbol     = 'modified_motor_P.Store_run_pulse_InitialValue';
pt(20).baseaddr   = '&modified_motor_P.Store_run_pulse_InitialValue';
pt(20).dtname     = 'real_T';



  
pt(21).blockname = 'motor_subsystem/Motor Selector/Constant';
pt(21).paramname = 'Value';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';
pt(21).isStruct  = false;
pt(21).symbol     = 'modified_motor_P.Constant_Value';
pt(21).baseaddr   = '&modified_motor_P.Constant_Value';
pt(21).dtname     = 'real_T';



  
pt(22).blockname = 'motor_subsystem/Motor Selector/Gate1';
pt(22).paramname = 'Threshold';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';
pt(22).isStruct  = false;
pt(22).symbol     = 'modified_motor_P.Gate1_Threshold';
pt(22).baseaddr   = '&modified_motor_P.Gate1_Threshold';
pt(22).dtname     = 'real_T';



  
pt(23).blockname = 'motor_subsystem/Motor Selector/Gate2';
pt(23).paramname = 'Threshold';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';
pt(23).isStruct  = false;
pt(23).symbol     = 'modified_motor_P.Gate2_Threshold';
pt(23).baseaddr   = '&modified_motor_P.Gate2_Threshold';
pt(23).dtname     = 'real_T';



  
pt(24).blockname = 'motor_subsystem/Real motor/Saturation';
pt(24).paramname = 'UpperLimit';
pt(24).class     = 'scalar';
pt(24).nrows     = 1;
pt(24).ncols     = 1;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';
pt(24).isStruct  = false;
pt(24).symbol     = 'modified_motor_P.Saturation_UpperSat_a';
pt(24).baseaddr   = '&modified_motor_P.Saturation_UpperSat_a';
pt(24).dtname     = 'real_T';



  
pt(25).blockname = 'motor_subsystem/Real motor/Saturation';
pt(25).paramname = 'LowerLimit';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';
pt(25).isStruct  = false;
pt(25).symbol     = 'modified_motor_P.Saturation_LowerSat_d';
pt(25).baseaddr   = '&modified_motor_P.Saturation_LowerSat_d';
pt(25).dtname     = 'real_T';



  
pt(26).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(26).paramname = 'P1';
pt(26).class     = 'scalar';
pt(26).nrows     = 1;
pt(26).ncols     = 1;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';
pt(26).isStruct  = false;
pt(26).symbol     = 'modified_motor_P.Q4DA_P1';
pt(26).baseaddr   = '&modified_motor_P.Q4DA_P1';
pt(26).dtname     = 'real_T';



  
pt(27).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(27).paramname = 'P2';
pt(27).class     = 'scalar';
pt(27).nrows     = 1;
pt(27).ncols     = 1;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';
pt(27).isStruct  = false;
pt(27).symbol     = 'modified_motor_P.Q4DA_P2';
pt(27).baseaddr   = '&modified_motor_P.Q4DA_P2';
pt(27).dtname     = 'real_T';



  
pt(28).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(28).paramname = 'P3';
pt(28).class     = 'scalar';
pt(28).nrows     = 1;
pt(28).ncols     = 1;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';
pt(28).isStruct  = false;
pt(28).symbol     = 'modified_motor_P.Q4DA_P3';
pt(28).baseaddr   = '&modified_motor_P.Q4DA_P3';
pt(28).dtname     = 'real_T';



  
pt(29).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(29).paramname = 'P4';
pt(29).class     = 'scalar';
pt(29).nrows     = 1;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';
pt(29).isStruct  = false;
pt(29).symbol     = 'modified_motor_P.Q4DA_P4';
pt(29).baseaddr   = '&modified_motor_P.Q4DA_P4';
pt(29).dtname     = 'real_T';



  
pt(30).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(30).paramname = 'P5';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';
pt(30).isStruct  = false;
pt(30).symbol     = 'modified_motor_P.Q4DA_P5';
pt(30).baseaddr   = '&modified_motor_P.Q4DA_P5';
pt(30).dtname     = 'real_T';



  
pt(31).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(31).paramname = 'P6';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';
pt(31).isStruct  = false;
pt(31).symbol     = 'modified_motor_P.Q4DA_P6';
pt(31).baseaddr   = '&modified_motor_P.Q4DA_P6';
pt(31).dtname     = 'real_T';



  
pt(32).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(32).paramname = 'P7';
pt(32).class     = 'scalar';
pt(32).nrows     = 1;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';
pt(32).isStruct  = false;
pt(32).symbol     = 'modified_motor_P.Q4DA_P7';
pt(32).baseaddr   = '&modified_motor_P.Q4DA_P7';
pt(32).dtname     = 'real_T';



  
pt(33).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(33).paramname = 'P8';
pt(33).class     = 'scalar';
pt(33).nrows     = 1;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';
pt(33).isStruct  = false;
pt(33).symbol     = 'modified_motor_P.Q4DA_P8';
pt(33).baseaddr   = '&modified_motor_P.Q4DA_P8';
pt(33).dtname     = 'real_T';



  
pt(34).blockname = 'motor_subsystem/Real motor/Q4 DA ';
pt(34).paramname = 'P9';
pt(34).class     = 'scalar';
pt(34).nrows     = 1;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';
pt(34).isStruct  = false;
pt(34).symbol     = 'modified_motor_P.Q4DA_P9';
pt(34).baseaddr   = '&modified_motor_P.Q4DA_P9';
pt(34).dtname     = 'real_T';



  
pt(35).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(35).paramname = 'P1';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';
pt(35).isStruct  = false;
pt(35).symbol     = 'modified_motor_P.Q4Enc_P1';
pt(35).baseaddr   = '&modified_motor_P.Q4Enc_P1';
pt(35).dtname     = 'real_T';



  
pt(36).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(36).paramname = 'P2';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';
pt(36).isStruct  = false;
pt(36).symbol     = 'modified_motor_P.Q4Enc_P2';
pt(36).baseaddr   = '&modified_motor_P.Q4Enc_P2';
pt(36).dtname     = 'real_T';



  
pt(37).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(37).paramname = 'P3';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';
pt(37).isStruct  = false;
pt(37).symbol     = 'modified_motor_P.Q4Enc_P3';
pt(37).baseaddr   = '&modified_motor_P.Q4Enc_P3';
pt(37).dtname     = 'real_T';



  
pt(38).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(38).paramname = 'P4';
pt(38).class     = 'scalar';
pt(38).nrows     = 1;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';
pt(38).isStruct  = false;
pt(38).symbol     = 'modified_motor_P.Q4Enc_P4';
pt(38).baseaddr   = '&modified_motor_P.Q4Enc_P4';
pt(38).dtname     = 'real_T';



  
pt(39).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(39).paramname = 'P5';
pt(39).class     = 'scalar';
pt(39).nrows     = 1;
pt(39).ncols     = 1;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';
pt(39).isStruct  = false;
pt(39).symbol     = 'modified_motor_P.Q4Enc_P5';
pt(39).baseaddr   = '&modified_motor_P.Q4Enc_P5';
pt(39).dtname     = 'real_T';



  
pt(40).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(40).paramname = 'P6';
pt(40).class     = 'scalar';
pt(40).nrows     = 1;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';
pt(40).isStruct  = false;
pt(40).symbol     = 'modified_motor_P.Q4Enc_P6';
pt(40).baseaddr   = '&modified_motor_P.Q4Enc_P6';
pt(40).dtname     = 'real_T';



  
pt(41).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(41).paramname = 'P7';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';
pt(41).isStruct  = false;
pt(41).symbol     = 'modified_motor_P.Q4Enc_P7';
pt(41).baseaddr   = '&modified_motor_P.Q4Enc_P7';
pt(41).dtname     = 'real_T';



  
pt(42).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(42).paramname = 'P8';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';
pt(42).isStruct  = false;
pt(42).symbol     = 'modified_motor_P.Q4Enc_P8';
pt(42).baseaddr   = '&modified_motor_P.Q4Enc_P8';
pt(42).dtname     = 'real_T';



  
pt(43).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(43).paramname = 'P9';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';
pt(43).isStruct  = false;
pt(43).symbol     = 'modified_motor_P.Q4Enc_P9';
pt(43).baseaddr   = '&modified_motor_P.Q4Enc_P9';
pt(43).dtname     = 'real_T';



  
pt(44).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(44).paramname = 'P10';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';
pt(44).isStruct  = false;
pt(44).symbol     = 'modified_motor_P.Q4Enc_P10';
pt(44).baseaddr   = '&modified_motor_P.Q4Enc_P10';
pt(44).dtname     = 'real_T';



  
pt(45).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(45).paramname = 'P11';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';
pt(45).isStruct  = false;
pt(45).symbol     = 'modified_motor_P.Q4Enc_P11';
pt(45).baseaddr   = '&modified_motor_P.Q4Enc_P11';
pt(45).dtname     = 'real_T';



  
pt(46).blockname = 'motor_subsystem/Real motor/Q4 Enc ';
pt(46).paramname = 'P12';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';
pt(46).isStruct  = false;
pt(46).symbol     = 'modified_motor_P.Q4Enc_P12';
pt(46).baseaddr   = '&modified_motor_P.Q4Enc_P12';
pt(46).dtname     = 'real_T';



  
pt(47).blockname = 'motor_subsystem/Simulated Motor/Integrator';
pt(47).paramname = 'InitialCondition';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';
pt(47).isStruct  = false;
pt(47).symbol     = 'modified_motor_P.Integrator_IC_a';
pt(47).baseaddr   = '&modified_motor_P.Integrator_IC_a';
pt(47).dtname     = 'real_T';



  
pt(48).blockname = 'motor_subsystem/Simulated Motor/Integrator1';
pt(48).paramname = 'InitialCondition';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';
pt(48).isStruct  = false;
pt(48).symbol     = 'modified_motor_P.Integrator1_IC';
pt(48).baseaddr   = '&modified_motor_P.Integrator1_IC';
pt(48).dtname     = 'real_T';



  
pt(49).blockname = 'motor_subsystem/Simulated Motor/Integrator2';
pt(49).paramname = 'InitialCondition';
pt(49).class     = 'scalar';
pt(49).nrows     = 1;
pt(49).ncols     = 1;
pt(49).subsource = 'SS_DOUBLE';
pt(49).ndims     = '2';
pt(49).size      = '[]';
pt(49).isStruct  = false;
pt(49).symbol     = 'modified_motor_P.Integrator2_IC';
pt(49).baseaddr   = '&modified_motor_P.Integrator2_IC';
pt(49).dtname     = 'real_T';



  
pt(50).blockname = 'motor_subsystem/Switching Logic/Switch1';
pt(50).paramname = 'Threshold';
pt(50).class     = 'scalar';
pt(50).nrows     = 1;
pt(50).ncols     = 1;
pt(50).subsource = 'SS_DOUBLE';
pt(50).ndims     = '2';
pt(50).size      = '[]';
pt(50).isStruct  = false;
pt(50).symbol     = 'modified_motor_P.Switch1_Threshold';
pt(50).baseaddr   = '&modified_motor_P.Switch1_Threshold';
pt(50).dtname     = 'real_T';



  
pt(51).blockname = '';
pt(51).paramname = 'J';
pt(51).class     = 'scalar';
pt(51).nrows     = 1;
pt(51).ncols     = 1;
pt(51).subsource = 'SS_DOUBLE';
pt(51).ndims     = '2';
pt(51).size      = '[]';
pt(51).isStruct  = false;
pt(51).symbol     = 'modified_motor_P.J';
pt(51).baseaddr   = '&modified_motor_P.J';
pt(51).dtname     = 'real_T';



  
pt(52).blockname = '';
pt(52).paramname = 'Ke';
pt(52).class     = 'scalar';
pt(52).nrows     = 1;
pt(52).ncols     = 1;
pt(52).subsource = 'SS_DOUBLE';
pt(52).ndims     = '2';
pt(52).size      = '[]';
pt(52).isStruct  = false;
pt(52).symbol     = 'modified_motor_P.Ke';
pt(52).baseaddr   = '&modified_motor_P.Ke';
pt(52).dtname     = 'real_T';



  
pt(53).blockname = '';
pt(53).paramname = 'Kt';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';
pt(53).ndims     = '2';
pt(53).size      = '[]';
pt(53).isStruct  = false;
pt(53).symbol     = 'modified_motor_P.Kt';
pt(53).baseaddr   = '&modified_motor_P.Kt';
pt(53).dtname     = 'real_T';



  
pt(54).blockname = '';
pt(54).paramname = 'L';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';
pt(54).ndims     = '2';
pt(54).size      = '[]';
pt(54).isStruct  = false;
pt(54).symbol     = 'modified_motor_P.L';
pt(54).baseaddr   = '&modified_motor_P.L';
pt(54).dtname     = 'real_T';



  
pt(55).blockname = '';
pt(55).paramname = 'R';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_DOUBLE';
pt(55).ndims     = '2';
pt(55).size      = '[]';
pt(55).isStruct  = false;
pt(55).symbol     = 'modified_motor_P.R';
pt(55).baseaddr   = '&modified_motor_P.R';
pt(55).dtname     = 'real_T';



  
pt(56).blockname = '';
pt(56).paramname = 'b';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';
pt(56).ndims     = '2';
pt(56).size      = '[]';
pt(56).isStruct  = false;
pt(56).symbol     = 'modified_motor_P.b';
pt(56).baseaddr   = '&modified_motor_P.b';
pt(56).dtname     = 'real_T';



  
pt(57).blockname = '';
pt(57).paramname = 'image_data';
pt(57).class     = 'col-mat';
pt(57).nrows     = 3;
pt(57).ncols     = 3;
pt(57).subsource = 'SS_DOUBLE';
pt(57).ndims     = '2';
pt(57).size      = '[]';
pt(57).isStruct  = false;
pt(57).symbol     = 'modified_motor_P.image_data';
pt(57).baseaddr   = '&modified_motor_P.image_data[0]';
pt(57).dtname     = 'real_T';


function len = getlenPT
len = 57;

