program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i,j:integer;
begin
  for i:=1 to 26 do begin
  assign(output,'test.txt');
  writeln(100000,' ',100000);
  for i:=1 to 100000 do write('A');
  end;
end.
