program ZAD_1;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   max,s,s1:string;
   i,j,p:integer;
begin
   readln(s);
   max:=s[1];
   for i:=1 to trunc(power(2,length(s))-1) do
      begin
         j:=i;
         p:=1;
         s1:='';
         while j>0 do
            begin
               if  odd(j) then s1:=s1+s[p];
               inc(p);
               j:=j div 2;
            end;
         p:=length(s1) div 2+1;
         for j:=1 to p do
            begin
               if (s1[j]<>s1[length(s1)-j+1]) then break;
               if (j=p) and (s1>max) then max:=s1;
            end;
      end;
   writeln(max);
   readln;
end.
