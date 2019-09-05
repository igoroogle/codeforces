program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m,i:integer;
begin
   readln(n,m);
   i:=0;
   while n<>0 do
      begin
         dec(n);
         inc(i);
         if (i mod m = 0) then inc(n);
      end;
   writeln(i);
   readln;
end.
