program tset30;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i:integer;
begin
   assign(output,'input.txt');
   writeln('500000 1');
   for i:=1 to 500000 do writeln('1000000000 1000000000');
end.