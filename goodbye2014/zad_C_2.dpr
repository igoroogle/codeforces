program zad_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, m, ss, j, c : integer;
  ar : array[1 .. 501] of int64;
  ar1, p, use : array[1 .. 1001] of integer;
  res, w : int64;
begin
  readln(n, m);
  for i := 1 to n do
    read(ar[i]);
  for i := 1 to m do
    read(ar1[i]);

  ss := 0;
  for i := 1 to m do begin
    for j := 1 to ss do
      if(p[j] = ar1[i]) then
        break;
    if(j > ss) or (ss = 0) then begin
      inc(ss);
      p[ss] := ar1[i];
      use[ar1[i]] := 1;
    end;
  end;

  for i := 1 to n do
    if(use[i] = 0) then begin
      inc(ss);
      p[ss] := i;
    end;

  res := 0;

  for i := 1 to m do begin
    w := 0;
    for j := 1 to n do
      if(p[j] = ar1[i]) then
        break
      else
        inc(w, ar[p[j]]);
    inc(res, w);

    
    c := p[j];
    for j := j - 1 downto 1 do
      p[j + 1] := p[j];
    p[1] := c;
  end;

  writeln(res);
end.
