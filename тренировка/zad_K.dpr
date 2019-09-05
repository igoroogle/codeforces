program zad_K;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, i, j, k : integer;
  max, sum : int64;
  use : array[1 .. 100100] of integer;
  ar, p : array[1 .. 100100] of int64;

procedure qsort(l, r : integer);
  var
    i, j : integer;
    m, c : int64;
  begin
    i := l;
    j := r;
    m := ar[i + random(r - l + 1)];
    repeat
      while(ar[i] > m) do inc(i);
      while(ar[j] < m) do dec(j);
      if(i <= j) then begin
        c := ar[i];
        ar[i] := ar[j];
        ar[j] := c;
        c := p[i];
        p[i] := p[j];
        p[j] := c;

        inc(i);
        dec(j);
      end;
    until (i > j);
    if(i < r) then qsort(i, r);
    if(j > l) then qsort(l, j);
  end;
begin
  readln(n);
  for i := 1 to n do begin
    read(ar[i]);
    p[i] := i;
    sum := sum + ar[i];
  end;

  qsort(1, n);
  max := 0;
  i := 1;
  j := 1;
  for k := 1 to n do begin
    if(k mod 2 <> 0) then begin
      while(use[p[i]] = 1) do
        inc(i);
      max := max + ar[i];
      use[p[i]] := 1;
    end else begin
      while(use[j] = 1) do
        inc(j);
      use[j] := 1;
    end;
  end;

  writeln(max, ' ', sum - max);


  readln(n);
end.
