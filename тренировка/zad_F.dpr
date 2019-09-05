program zad_F;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  a, b, c, m : extended;
begin
  readln(a, b, c);
  m := ((a + b) * (b - a + 1) / 2 + (a * 2 + b * 2)*(b - a + 1)/2)/(2 * (b - a + 1));

  if(c <m)then
    writeln('Take another envelope')
  else
    writeln('Stay with this envelope');
  readln(a);
end.
