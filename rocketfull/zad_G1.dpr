program zad_G1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, k, s, i : integer;
  a : array[0 .. 1100] of integer;
  st : string;

  res : extended;

procedure per(l, r : integer; var st : string);
  var
    i : integer;
    c : char;
  begin
    for i := l to l + ((r - l) div 2) do begin
      c := st[i];
      st[i] := st[r + l - i];
      st[r + l - i] := c;
    end;
  end;

procedure rec(p : integer; st : string);
  var
    i, j, kol : integer;
  begin
    if(p > k) then begin
      kol := 0;
      for i := 1 to n do
        for j := i + 1 to n do
          if(st[i] > st[j]) then
            inc(kol);
      inc(a[kol]);
    end else begin
      for i := 1 to n do
        for j := i to n do begin
          per(i, j, st);
          rec(p + 1, st);
          per(i, j, st);
        end;
    end;
  end;
begin
  readln(n, k);
  readln(st);

  while(pos(' ', st) <> 0) do
    delete(st, pos(' ', st), 1);

  rec(1, st);

  s := 0;
  for i := 0 to 1000 do
    inc(s, a[i]);

  res := 0;
  for i := 0 to 1000 do
    if(a[i] > 0) then
      res := res + 1.0 * a[i] * i / s;

  writeln(res);

  readln(n);
end.
 