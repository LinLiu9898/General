
set nocompatible
filetype off
filetype plugin on
behave mswin

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

nnoremap test :-1read C:\Users\Home-T410\Desktop\Template\test.cpp<CR>:call TrimEndLines()<CR>64<CR>
nnoremap cpp :-1read C:\Users\Home-T410\Desktop\Template\template.cpp<CR>:call TrimEndLines()<CR>64<CR>
nnoremap frac :-1read C:\Users\Home-T410\Desktop\Template\Fractions.cpp<CR>
nnoremap bigint :-1read C:\Users\Home-T410\Desktop\Template\BigInt.cpp<CR>
nnoremap umap :-1read C:\Users\Home-T410\Desktop\Template\Unordered_MapHash.cpp<CR>
nnoremap modular :-1read C:\Users\Home-T410\Desktop\Template\ModularArithmetic.cpp<CR>
nnoremap open : :tabnew C:\Users\Home-T410\Desktop\Vim\A.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\B.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\C.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\D.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\E.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\F.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\G.cpp<CR>:tabnew C:\Users\Home-T410\Desktop\Vim\H.cpp<CR>:tabr<CR>:q!<CR>

"autocmd filetype cpp nnoremap <F5> :w <bar> !g++ -std=c++17 -O2 -Wall % -o %:r -Wl,--stack,268435456 && %:r.exe <CR>
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 % -O2 -Wuninitialized -Wparentheses -Wall -Wextra -Wno-sign-conversion -Wshadow -DLOCAL -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F10> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $$
autocmd filetype cpp nnoremap <C-A> :%s#\($\n\s*\)\+\%$##<CR>

"compilation flags for precompiling
"g++ -std=c++17 -O2 -Wuninitialized -Wparentheses -Wall -Wextra -Wno-sign-conversion -Wshadow -DLOCAL

function TrimEndLines()
    let save_cursor = getpos(".")
    silent! %s#\($\n\s*\)\+\%$##
    call setpos('.', save_cursor)
endfunction

autocmd BufWritePre *.cpp call TrimEndLines()
