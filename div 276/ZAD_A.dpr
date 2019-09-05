program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,a,m:int64;
   i:integer;
begin
   readln(a,m);
   x:=a;
   for i:=1 to 1000000 do
       begin
          if (x mod m = 0) then
             begin
                writeln('Yes');
                readln;
                halt;
             end;
          x:=x+x mod m;
       end;
   writeln('No');
   readln;
end.
