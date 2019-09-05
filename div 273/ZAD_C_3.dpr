program zad_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  r,g,b,s,c:int64;

function fuq(r,g,b:int64):boolean;
  begin
    fuq:=false;
    if(r<>0) and (g<>0) and (r+g> 2) then fuq:=true
    else if (r<>0) and (b<>0) and (r+b>2) then fuq:=true
    else if (b<>0) and (g<>0) and (g+b>2) then fuq:=true
    else if (b<>0) and (g<>0) and (r<>0) and (r+g+b>2) then fuq:=true;
  end;
begin
  readln(r,g,b);
  s:=0;
  if (g<b) then
     begin
        c:=g;
        g:=b;
        b:=c;
     end;
  if (r<g) then
     begin
        c:=r;
        r:=g;
        g:=c;
     end;
  if (g<b) then
     begin
        c:=g;
        g:=b;
        b:=c;
     end;
  while (fuq(r,g,b)) do
     begin
        if(r = g) and (r = b) then begin
        inc(s, r);
        r:=0;
        b:=0;
        g:=0;
    end else if (b<>0) then
            begin
                if(r >= trunc(1.0 * b * 2)) then begin s := s + b;
                  r := r - trunc(1.0 * b * 2);
        b := 0
      end else  begin
        s := s + (r div 2);
        b := b - (r div 2);
        r := r - trunc(1.0 * (r div 2) * 2);
      end;
    end else begin
      if(r >= trunc(1.0 * g * 2)) then begin
        s := s + g;
        r := r - trunc(1.0 * g * 2);
        g := 0
      end else  begin
        s := s + (r div 2);
        g := g - (r div 2);
        r := r - trunc(1.0 * (r div 2) * 2);
      end;
    end;
    if(g < b) then begin
      c := g;
      g := b;
      b := c;
    end;
    if(r < g) then begin
      c := r;
      r := g;
      g := c;
    end;
    if(g < b) then begin
      c := g;
      g := b;
      b := c;
    end;
  end;

  writeln(s);
  readln;
  readln;
end.
