program zad_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, m, k, res, i, step, step1, kol : integer;
  ar : array[1 .. 1100] of integer;
begin
  readln(n, m, k);
  for i := 1 to m + 1 do
    readln(ar[i]);

  step := 33554432;
  res := 0;
  for i := 1 to m do begin
    step1 := step;
    kol := 0;
    while(step1 <> 0) do begin
      if (ar[i] and step1 <> ar[m + 1] and step1) then
        inc(kol);
      step1 := step1 div 2;
    end;
    if(kol <= k) then
      inc(res);
  end;

  writeln(res);

  readln(n);
end.
