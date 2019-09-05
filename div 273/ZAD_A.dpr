program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,c,d,e,i:integer;
begin
   readln(a,b,c,d,e);
   for i := 1 to 10000 do
    if ((a+b+c+d+e) div i = 5) and ((a+b+c+d+e) mod i = 0) then
       begin
          writeln(i);
          readln;
          halt;
       end;
   writeln(-1);
   readln;
end.
