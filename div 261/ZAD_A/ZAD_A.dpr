program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x1,y1,x2,y2,l:integer;
begin
readln(x1, y1, x2, y2);
  if(x1 <> x2) and (y1 = y2) then begin
    l := abs(x1 - x2);
    writeln(x1, ' ', y1 + l, ' ', x2, ' ', y2 + l);
  end else if (x1 = x2) and (y1 <> y2) then begin
    l := abs(y1 - y2);
    writeln(x1 + l, ' ', y1, ' ', x2 + l, ' ', y2);
  end else if(abs(x1 - x2) = abs(y1 - y2)) then begin
    writeln(x1, ' ', y2, ' ', x2, ' ', y1);
  end else
    writeln(-1);
end.
