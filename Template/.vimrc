set nocompatible
filetype off
filetype plugin on

source $VIMRUNTIME/vimrc_example.vim

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'joshdick/onedark.vim'

call vundle#end()
filetype plugin indent on

behave mswin
syntax on
colorscheme onedark

au GUIEnter * simalt ~x

set backspace=indent,eol,start
set is
set clipboard=unnamed
set guifont=*
set tabstop=4
set shiftwidth=4
set smartindent
set autoindent
set nocompatible
set number
set relativenumber
set nowrap
set mouse=a
set background=dark
set noerrorbells

inore jj <Esc>
map <F2> :%y <CR>:w <CR>
map <F5> :w <CR>:%y <CR>
map vimrc :e! $HOME\_vimrc<CR>

function GuiTabLabel()
    let label = ''
    let bufnrlist = tabpagebuflist(v:lnum)

    for bufnr in bufnrlist
        if getbufvar(bufnr, "&modified")
            let label = '+'
            break
        endif
    endfor

    let wincount = tabpagewinnr(v:lnum, '$')
    if wincount > 1
        let label .= wincount
    endif
    if label != ''
        let label .= ' '
    endif

    return label . "%t"
endfunction

set guitablabel=%!GuiTabLabel()

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

"inoremap " ""<left>
"inoremap ' ''<left>
"inoremap [ []<left>
let g:vim_be_good_floating = 0
nnoremap test :-1read C:\Users\Home-T410\Desktop\Template\test.cpp<CR>129<CR>
nnoremap cpp :-1read C:\Users\Home-T410\Desktop\Template\template.cpp<CR>128<CR> 
nnoremap frac :-1read C:\Users\Home-T410\Desktop\Template\Fractions.cpp<CR>
nnoremap bigint :-1read C:\Users\Home-T410\Desktop\Template\BigInt.cpp<CR>
nnoremap open : :tabnew C:\Users\Home-T410\Desktop\Vim\A.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\B.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\C.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\D.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\E.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\F.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\G.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\H.cpp<CR>:tabr<CR>:q!<CR>

autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 % -O2 -Wall -Wextra -Wno-sign-conversion -Wshadow -DLOCAL -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F10> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $$

set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction
