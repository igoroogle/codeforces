program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   s,i:integer;
   n:int64;
begin
   readln(n);
   s:=0;
   for i:=1 to 1010000 do
      if ((n+i) mod 3 = 0) and (((n+i) div 3) >= trunc((1.0 * (1+i) * i) / 2)) then inc(s); 
   writeln(s);
   readln;
end.
