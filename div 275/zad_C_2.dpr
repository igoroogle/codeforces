program zad_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,k,j,p:integer;
  ar: array[1 .. 100100] of integer;
begin
  readln(n, k);

  j := 1;
  p:=n;
  for i := 1 to k do
    if(i mod 2 = 0) then begin
      ar[i]:=p;
      dec(p);
    end else begin
      ar[i] := j;
      inc(j);
    end;
  for i := k + 1 to n do begin
    if(k mod 2 = 0) then begin
      ar[i] := p;
      dec(p);
    end else begin
      ar[i] := j;
      inc(j);
    end;
  end;

  for i := 1 to n do
    write(ar[i], ' ');
  readln;
  readln;
end.
