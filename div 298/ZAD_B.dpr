program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [0..110,-4010..4010] of integer;
   v1,v2,t,d,i,j,k:integer;
begin
   read(v1,v2,t,d);
   for i:=0 to 110 do
      for j:=-4010 to 4010 do a[i,j]:=-maxint;
   a[1,v1]:=v1;
   for i:=2 to t do
      for j:=-2000 to 2000 do
         for k:=j-d to j+d do
            if  (a[i-1,k]>-maxint) and (a[i-1,k]+abs(j)>a[i,j]) then
               a[i,j]:=a[i-1,k]+abs(j);
   writeln(a[t,v2]);
   readln;
   readln;
end.
