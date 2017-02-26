Program ProgramEightChapterFive;
const
max_flight=8;
max_data_for_each_flight=2;
type
range_flight_numbers=1..max_flight;
range_data=1..max_data_for_each_flight;
arr=array[range_flight_numbers,range_data] of integer;
str=string[255];
var
time_hour,time_minute,p:integer;
s:str;
const
a:arr=(( 8, 0),( 9,43),(11,19),(12,47),(14, 0),(15,45),(19, 0),(21,45));
b:arr=((10,16),(11,52),(13,31),(15, 0),(16, 8),(17,55),(21,20),(23,58));
procedure InputData;
  const
  obj:str=':';
  var
  position:integer;
  cycle:boolean;
  code:integer;
  begin
  cycle:=false;
  repeat
  write('Please Enter your flight time(hh:mm) in 24-hour form:');
  readln(s);
  position:=pos(obj,s);
  code:=0;
  if ((position<=1) or (position>=length(s))) then cycle:=true;
  if not(cycle) then begin val(copy(s,1,position-1),time_hour,code);if code<>0 then cycle:=true;end;
  if not(cycle) then begin val(copy(s,position+1,length(s)-position),time_minute,code);if code<>0 then cycle:=true;end;
  if cycle then writeln('Input error please try again!');
  until not(cycle);
  end;
function Convert(array_name:arr;number:integer):integer;
  begin
  Convert:=array_name[number,1]*60+array_name[number,2];
  end;
procedure FindMax(var p:integer);
  var
  input_convert_to_minutes,i,distance:integer;
  begin
  input_convert_to_minutes:=time_hour*60+time_minute;
  p:=1;distance:=abs(input_convert_to_minutes-Convert(a,1));
  for i:= 2 to max_flight do
	if abs(input_convert_to_minutes-Convert(a,i))<distance then
	  begin
	  p:=i;
	  distance:=abs(input_convert_to_minutes-Convert(a,i));
	  end;
  end;
procedure OutputData(p:integer);
  begin
  write('The closest flight is leaving at ',a[p,1]:2,':',a[p,2]:2,' and arriving at ',b[p,1]:2,':',b[p,2]:2);
  readln;
  end;
procedure Main;
  begin
  Inputdata;
  Findmax(p);
  OutputData(p);
  end;
{==============Main================}
begin
main;
end.