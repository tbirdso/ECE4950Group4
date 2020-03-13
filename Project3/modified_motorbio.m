function bio=modified_motorbio
bio = [];
bio(1).blkName='Imager/Process Image';
bio(1).sigName='image_data_sig';
bio(1).portIdx=0;
bio(1).dim=[100,3];
bio(1).sigWidth=300;
bio(1).sigAddress='&modified_motor_B.image_data_fixed[0]';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='Logic Block/Generate Angles List/p1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[100,1];
bio(2).sigWidth=100;
bio(2).sigAddress='&modified_motor_B.angles_vector[0]';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='Logic Block/Generate Angles List/p2';
bio(3).sigName='num_angles';
bio(3).portIdx=1;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&modified_motor_B.num_angles';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

bio(4).blkName='Logic Block/Rate Transition';
bio(4).sigName='target_pos';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&modified_motor_B.target_pos';
bio(4).ndims=2;
bio(4).size=[];
bio(4).isStruct=false;

bio(5).blkName='Logic Block/Rate Transition1';
bio(5).sigName='a_v';
bio(5).portIdx=0;
bio(5).dim=[100,1];
bio(5).sigWidth=100;
bio(5).sigAddress='&modified_motor_B.a_v[0]';
bio(5).ndims=2;
bio(5).size=[];
bio(5).isStruct=false;

bio(6).blkName='UI/Data Type Conversion';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&modified_motor_B.DataTypeConversion';
bio(6).ndims=2;
bio(6).size=[];
bio(6).isStruct=false;

bio(7).blkName='UI/Data Type Conversion1';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&modified_motor_B.DataTypeConversion1';
bio(7).ndims=2;
bio(7).size=[];
bio(7).isStruct=false;

bio(8).blkName='UI/Data Type Conversion2';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&modified_motor_B.DataTypeConversion2';
bio(8).ndims=2;
bio(8).size=[];
bio(8).isStruct=false;

bio(9).blkName='motor_subsystem/Derivative';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&modified_motor_B.Derivative';
bio(9).ndims=2;
bio(9).size=[];
bio(9).isStruct=false;

bio(10).blkName='motor_subsystem/Gain';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&modified_motor_B.Gain';
bio(10).ndims=2;
bio(10).size=[];
bio(10).isStruct=false;

bio(11).blkName='motor_subsystem/KI';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&modified_motor_B.KI';
bio(11).ndims=2;
bio(11).size=[];
bio(11).isStruct=false;

bio(12).blkName='motor_subsystem/Kd';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&modified_motor_B.Kd';
bio(12).ndims=2;
bio(12).size=[];
bio(12).isStruct=false;

bio(13).blkName='motor_subsystem/Kp';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&modified_motor_B.Kp';
bio(13).ndims=2;
bio(13).size=[];
bio(13).isStruct=false;

bio(14).blkName='motor_subsystem/Integrator';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&modified_motor_B.Integrator';
bio(14).ndims=2;
bio(14).size=[];
bio(14).isStruct=false;

bio(15).blkName='motor_subsystem/Saturation';
bio(15).sigName='Voltage_Input';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&modified_motor_B.Voltage_Input';
bio(15).ndims=2;
bio(15).size=[];
bio(15).isStruct=false;

bio(16).blkName='motor_subsystem/Sum';
bio(16).sigName='DTheta';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&modified_motor_B.DTheta';
bio(16).ndims=2;
bio(16).size=[];
bio(16).isStruct=false;

bio(17).blkName='motor_subsystem/Sum1';
bio(17).sigName='Pos_Input';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&modified_motor_B.Pos_Input';
bio(17).ndims=2;
bio(17).size=[];
bio(17).isStruct=false;

bio(18).blkName='Logic Block/Clock/Sum';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&modified_motor_B.Sum';
bio(18).ndims=2;
bio(18).size=[];
bio(18).isStruct=false;

bio(19).blkName='Logic Block/Clock/Unit Delay';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&modified_motor_B.UnitDelay';
bio(19).ndims=2;
bio(19).size=[];
bio(19).isStruct=false;

bio(20).blkName='Logic Block/Position Iterator/Position_List';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[100,1];
bio(20).sigWidth=100;
bio(20).sigAddress='&modified_motor_B.Position_List[0]';
bio(20).ndims=2;
bio(20).size=[];
bio(20).isStruct=false;

bio(21).blkName='Logic Block/Position Iterator/Iterator/p1';
bio(21).sigName='target_pos';
bio(21).portIdx=0;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&modified_motor_B.target_pos_o';
bio(21).ndims=2;
bio(21).size=[];
bio(21).isStruct=false;

bio(22).blkName='Logic Block/Position Iterator/Iterator/p2';
bio(22).sigName='iter_next_index';
bio(22).portIdx=1;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&modified_motor_B.next_index';
bio(22).ndims=2;
bio(22).size=[];
bio(22).isStruct=false;

bio(23).blkName='Logic Block/Position Iterator/Iterator/p3';
bio(23).sigName='';
bio(23).portIdx=2;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&modified_motor_B.next_run';
bio(23).ndims=2;
bio(23).size=[];
bio(23).isStruct=false;

bio(24).blkName='Logic Block/Position Iterator/Data Store Read';
bio(24).sigName='iter_cur_index';
bio(24).portIdx=0;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&modified_motor_B.iter_cur_index';
bio(24).ndims=2;
bio(24).size=[];
bio(24).isStruct=false;

bio(25).blkName='Logic Block/Position Iterator/Data Store Read1';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&modified_motor_B.DataStoreRead1';
bio(25).ndims=2;
bio(25).size=[];
bio(25).isStruct=false;

bio(26).blkName='Logic Block/Position Iterator/TmpSignal ConversionAtHiddenToAsyncQueue_InsertedFor_Selector1_at_outport_0Inport1';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[2,1];
bio(26).sigWidth=2;
bio(26).sigAddress='&modified_motor_B.TmpSignalConversionAtHiddenToAs[0]';
bio(26).ndims=2;
bio(26).size=[];
bio(26).isStruct=false;

bio(27).blkName='Logic Block/Position Iterator/TmpSignal ConversionAtHiddenToAsyncQueue_InsertedFor_Selector_at_outport_0Inport1';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[2,1];
bio(27).sigWidth=2;
bio(27).sigAddress='&modified_motor_B.TmpSignalConversionAtHiddenTo_i[0]';
bio(27).ndims=2;
bio(27).size=[];
bio(27).isStruct=false;

bio(28).blkName='motor_subsystem/Motor Selector/Add';
bio(28).sigName='Switch Position';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&modified_motor_B.SwitchPosition';
bio(28).ndims=2;
bio(28).size=[];
bio(28).isStruct=false;

bio(29).blkName='motor_subsystem/Motor Selector/Gate1';
bio(29).sigName='Simulated Motor';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&modified_motor_B.SimulatedMotor';
bio(29).ndims=2;
bio(29).size=[];
bio(29).isStruct=false;

bio(30).blkName='motor_subsystem/Motor Selector/Gate2';
bio(30).sigName='Real Motor';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&modified_motor_B.RealMotor';
bio(30).ndims=2;
bio(30).size=[];
bio(30).isStruct=false;

bio(31).blkName='motor_subsystem/Real motor/Convert to Rad';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&modified_motor_B.y';
bio(31).ndims=2;
bio(31).size=[];
bio(31).isStruct=false;

bio(32).blkName='motor_subsystem/Real motor/Invert Sign';
bio(32).sigName='Position (rad)';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&modified_motor_B.Positionrad';
bio(32).ndims=2;
bio(32).size=[];
bio(32).isStruct=false;

bio(33).blkName='motor_subsystem/Real motor/Saturation';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&modified_motor_B.Saturation';
bio(33).ndims=2;
bio(33).size=[];
bio(33).isStruct=false;

bio(34).blkName='motor_subsystem/Real motor/Q4 Enc ';
bio(34).sigName='Position (steps)';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&modified_motor_B.Positionsteps';
bio(34).ndims=2;
bio(34).size=[];
bio(34).isStruct=false;

bio(35).blkName='motor_subsystem/Simulated Motor/Damping';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&modified_motor_B.Damping';
bio(35).ndims=2;
bio(35).size=[];
bio(35).isStruct=false;

bio(36).blkName='motor_subsystem/Simulated Motor/Inductance';
bio(36).sigName='d/dt(i)';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&modified_motor_B.ddti';
bio(36).ndims=2;
bio(36).size=[];
bio(36).isStruct=false;

bio(37).blkName='motor_subsystem/Simulated Motor/Inertia ';
bio(37).sigName='d2/dt2(theta)';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&modified_motor_B.d2dt2theta';
bio(37).ndims=2;
bio(37).size=[];
bio(37).isStruct=false;

bio(38).blkName='motor_subsystem/Simulated Motor/Ke';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&modified_motor_B.Ke';
bio(38).ndims=2;
bio(38).size=[];
bio(38).isStruct=false;

bio(39).blkName='motor_subsystem/Simulated Motor/Kt';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&modified_motor_B.Kt';
bio(39).ndims=2;
bio(39).size=[];
bio(39).isStruct=false;

bio(40).blkName='motor_subsystem/Simulated Motor/Resistance';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&modified_motor_B.Resistance';
bio(40).ndims=2;
bio(40).size=[];
bio(40).isStruct=false;

bio(41).blkName='motor_subsystem/Simulated Motor/Integrator';
bio(41).sigName='i';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&modified_motor_B.i';
bio(41).ndims=2;
bio(41).size=[];
bio(41).isStruct=false;

bio(42).blkName='motor_subsystem/Simulated Motor/Integrator1';
bio(42).sigName='d/dt(theta)';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&modified_motor_B.ddttheta';
bio(42).ndims=2;
bio(42).size=[];
bio(42).isStruct=false;

bio(43).blkName='motor_subsystem/Simulated Motor/Integrator2';
bio(43).sigName='theta';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&modified_motor_B.theta';
bio(43).ndims=2;
bio(43).size=[];
bio(43).isStruct=false;

bio(44).blkName='motor_subsystem/Simulated Motor/Add';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&modified_motor_B.Add';
bio(44).ndims=2;
bio(44).size=[];
bio(44).isStruct=false;

bio(45).blkName='motor_subsystem/Simulated Motor/Add1';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&modified_motor_B.Add1';
bio(45).ndims=2;
bio(45).size=[];
bio(45).isStruct=false;

bio(46).blkName='motor_subsystem/Switching Logic/Switch1';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&modified_motor_B.Switch1';
bio(46).ndims=2;
bio(46).size=[];
bio(46).isStruct=false;

function len = getlenBIO
len = 46;

