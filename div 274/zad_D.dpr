program zad_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n,l,x,y,s,r,rx,ry:int64;
  i:integer;
  ax,ay:boolean;
  ar : array[1..100100] of integer;
procedure binp(l : int64; var r : int64; rast : int64);
  var
    m,lt:int64;
  begin
    lt := l;

    while(l < r) do begin
      m:=(l+r) div 2;
      if(ar[m] - ar[lt] < rast) then
        l:=m+1
      else
        r:=m;
    end;
  end;
begin
  readln(n, l, x, y);
  for i := 1 to n do
    read(ar[i]);

  ax := true;
  ay := true;
  s := 2;
  for i := 1 to n do begin
    if(ax) then begin
      r := n;
      binp(i, r, x);
      if(ar[r] - ar[i] = x) then begin
        dec(s);
        ax := false;
      end;
    end;
    if(ay) then begin
      r := n;
      binp(i, r, y);
      if(ar[r] - ar[i] = y) then begin
        dec(s);
        ay := false;
      end;
    end;
  end;

  ry := -1;
  rx := -1;
  if(ax) and (ay) then begin
    for i := 1 to n do begin
      r := n;
      binp(i, r, y - x);
      if(ar[r] - ar[i] = y - x)then begin
        if(ar[r] + x <= l) then begin
          s := 1;
          rx := ar[r] + x;
          ax := false;
          ay := false;
          break;
        end else if (ar[i] - x >= ar[1]) then begin
          s := 1;
          rx := ar[i] - x;
          ax := false;
          ay := false;
          break;
        end;
      end;
      r := n;
      binp(i, r, y + x);
      if(ar[r] - ar[i] = y + x) then begin
        s := 1;
        rx := ar[i] + x;
        ax := false;
        ay := false;
        break;
      end;
    end;
    if(ax) and (ay) then begin
      rx := ar[1] + x;
      ry := ar[1] + y;
    end;
  end else if (ax) then
    rx := ar[1] + x
  else if (ay) then
    ry := ar[1] + y;

  writeln(s);
  if(rx <> -1) then
    write(rx, ' ');
  if(ry <> -1) then
    writeln(ry);
  readln;
  readln;
end.
