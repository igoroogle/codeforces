program ZAD_G;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, s, i, res : integer;
  money : int64;
  ar : array[1 .. 100100] of int64;
begin
  readln(n, s);
  for i := 1 to n do
    read(ar[i]);

  res := 0;
  while(s > 0) do begin
    money := 1;
    for i := 1 to n do
      if(money * ar[i] <= s) then
        money := money * ar[i]
      else
        break;
    res := res + (s div money);
    s := s mod money;
  end;

  writeln(res);

  readln(n);
end.
