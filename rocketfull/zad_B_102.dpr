program zad_B_102;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, m : int64;
function rec(sum, l, r : int64):string;
  var
    st : string;
    m1 : int64;
  begin
    str(sum, st);
    if(sum = n) then
      rec := ' ' + st + ' '
    else begin
      m1 := l + ((r - l) div 2);

      if(m <= m1) then
        rec := st + ' ' + rec(sum + 1, l, m1)
      else
        rec := rec(sum + 1, m1 + 1, r) + ' ' + st;
    end;
  end;
begin
  readln(n, m);

  writeln(rec(1, 1, 1 shl (n-1)));

  readln(n);
end.
