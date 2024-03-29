program zad_C_3;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  c, wr, wb, hr, hb, res, num, num1,u : int64;
  i : integer;
function get(x : integer):int64;
  var
    w : int64;
  begin
    if(trunc(1.0 * x * wr) > c) then begin
      get := 0;
      exit;
    end;

    w := (c - trunc(1.0 * x * wr)) div wb;
    get := trunc(1.0 * x * hr) +  trunc(1.0 * w * hb);
  end;

function nod(a, b : int64):int64;
  var
    r : int64;
  begin
    repeat
      r := a mod b;
      a := b;
      b := r;
    until(b = 0);

    nod := a;
  end;

function nok(a, b : int64):int64;
  begin
    nok := trunc(1.0 * (a div nod(a, b)) * b);
  end;
begin
  readln(c, hr, hb, wr, wb);

  num := nok(wr, wb);
  num1 := max(trunc(1.0 * hr * (num div wr)), trunc(1.0 * hb * (num div wb)));
  res := trunc(1.0 * max(0, (c div num) - 1) * num1);

  c := min(c, (c mod num) + num);

  num := 0;
  for i := 0 to c div wr do
    num := max(num, get(i));

  writeln(res + num);

  readln(c);
end.
