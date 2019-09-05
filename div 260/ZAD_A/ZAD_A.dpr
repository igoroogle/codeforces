program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..100010] of integer;
   i,x,y,n,max:integer;
begin
   readln(n);
   for i:=1 to n do a[i]:=0;
   for i:=1 to n do
      begin
         readln(x,y);
         a[x]:=y;
      end;
   max:=0;
   for i:=1 to n do
      begin
         if (a[i]<>0) and (a[i]<max) then
            begin
               writeln('Happy Alex');
               readln;
               halt;
            end
         else if (a[i]<>0) then max:=a[i];
      end;
   writeln('Poor Alex');
   readln;
end.
