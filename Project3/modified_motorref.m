function sys=modified_motorref
sys = [];
sys.child = [];
sys.NumDataTypes = 2; 
sys.DataTypes = [];
temp.EnumNames='';
temp.EnumValues = [];
temp.Name = '';
sys.DataTypes = repmat(temp,1,2);
sys.DataTypes(1).Name = 'real_T';
sys.DataTypes(2).Name = 'int8_T';