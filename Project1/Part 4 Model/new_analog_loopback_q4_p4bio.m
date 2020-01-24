function bio=new_analog_loopback_q4_p4bio
bio = [];
bio(1).blkName='Q4 Enc ';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&new_analog_loopback_q4_p4_B.Q4Enc';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

function len = getlenBIO
len = 1;

