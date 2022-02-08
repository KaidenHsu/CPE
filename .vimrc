" Set leaderkey to space
  let mapleader = " "

let g:polyglot_disabled = ['markdown']

" plugins
  call plug#begin()
  " plugin manager
  Plug 'tpope/vim-sensible'
  " useful plugins
  Plug 'sheerun/vim-polyglot'
  Plug 'preservim/nerdtree'
  Plug 'tiagofumo/vim-nerdtree-syntax-highlight'
  Plug 'ctrlpvim/ctrlp.vim'
  Plug 'majutsushi/tagbar'
  Plug 'jiangmiao/auto-pairs'
  Plug 'preservim/nerdcommenter'
  Plug 'tpope/vim-surround'
  Plug 'tpope/vim-repeat'
  Plug 'valloric/youcompleteme'
  Plug 'scrooloose/syntastic'
  Plug 'MarcWeber/vim-addon-mw-utils'
  Plug 'SirVer/ultisnips'
  Plug 'honza/vim-snippets'
  Plug 'Yggdroot/indentLine'
  " appearance
  Plug 'ryanoasis/vim-devicons'
  Plug 'vim-airline/vim-airline'
  Plug 'vim-airline/vim-airline-themes'
  " colorscheme
  Plug 'tomasr/molokai'
  Plug 'morhetz/gruvbox'
  Plug 'mhartington/oceanic-next'
  Plug 'jnurmine/Zenburn'
  Plug 'vim-scripts/wombat256.vim'
  call plug#end()


" plugins configuration

  " tagbar
    nmap <leader>t :TagbarToggle<CR>
    " get rid of redundent info
    let g:tagbar_compact = 1

  " NERDTree
    " get rid of redundent info
    let NERDTreeMinimalUI = 1
    nnoremap <leader>n :NERDTreeToggle<CR>
    " Exit Vim if NERDTree is the only window remaining in the only tab.
    autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
    " Close the tab if NERDTree is the only window remaining in it.
    autocmd BufEnter * if winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif

  " ctrlP
    let g:ctrlp_map = '<c-p>'


  " nerdcommenter
    " Add spaces after comment delimiters by default
    let g:NERDSpaceDelims = 1
    " Allow commenting and inverting empty lines (useful when commenting a region)
    let g:NERDCommentEmptyLines = 1
    " Enable trimming of trailing whitespace when uncommenting
    let g:NERDTrimTrailingWhitespace = 1
    " Enable NERDCommenterToggle to check all selected lines is commented or not
    let g:NERDToggleCheckAllLines = 1


  " youcompleteme
    " no preview window
      set completeopt-=preview
    " useful functions
      let g:ycm_filetype_blacklist = {
          \ 'tagbar' : 1,
          \ 'qf' : 1,
          \ 'notes' : 1,
          \ 'markdown' : 1,
          \ 'unite' : 1,
          \ 'text' : 1,
          \ 'vimwiki' : 1,
          \ 'gitcommit' : 1,
          \}
      let g:ycm_show_diagnostics_ui = 0



    " compatibility between youcompleteme and UltiSnips
      " disable youcompleteme list snippets
      let g:ycm_use_ultisnips_completer = 0

      function! g:UltiSnips_Complete()
        call UltiSnips#ExpandSnippet()
        if g:ulti_expand_res == 0
          if pumvisible()
            return "\<C-n>"
          else
            call UltiSnips#JumpForwards()
            if g:ulti_jump_forwards_res == 0
              return "\<TAB>"
            endif
          endif
        endif
        return ""
      endfunction

      function! g:UltiSnips_Reverse()
        call UltiSnips#JumpBackwards()
        if g:ulti_jump_backwards_res == 0
          return "\<C-P>"
        endif

        return ""
      endfunction


      if !exists("g:UltiSnipsJumpForwardTrigger")
        let g:UltiSnipsJumpForwardTrigger = "<tab>"
      endif
      if !exists("g:UltiSnipsJumpBackwardTrigger")
        let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
      endif


      au InsertEnter * exec "inoremap <silent> " . g:UltiSnipsExpandTrigger     . " <C-R>=g:UltiSnips_Complete()<cr>"
      au InsertEnter * exec "inoremap <silent> " .     g:UltiSnipsJumpBackwardTrigger . " <C-R>=g:UltiSnips_Reverse()<cr>"

  " syntastic
    let g:syntastic_python_checkers = ['pylint']
    " recommended settings
    set statusline+=%#warningmsg#
    set statusline+=%{SyntasticStatuslineFlag()}
    set statusline+=%*

    let g:syntastic_always_populate_loc_list = 1
    let g:syntastic_auto_loc_list = 1
    " let g:syntastic_check_on_open = 1
    let g:syntastic_check_on_wq = 0
    nnoremap <leader>ss :w<cr>:SyntasticCheck<CR>
    nnoremap <leader>sc :lclose<CR>
    nnoremap <leader>sn :lnext<CR>
    nnoremap <leader>sp :lprevious<CR>

  " indentLine
    let g:indentLine_char_list = ['┆']

  " vimdevicons
    " Disable adding devicons to vim-airline's tabline(default = 1)
    let g:webdevicons_enable_airline_tabline = 0
    " disable adding devicons to vim-airline's statusline(default = 1)
    let g:webdevicons_enable_airline_statusline = 0


  " vim-airline
    " vim tabline
    let g:airline#extensions#tabline#enabled = 1


  " vim-airline-themes
    let g:airline_theme='bubblegum'
    let g:airline_powerline_fonts = 1


  " gruvbox
    let g:gruvbox_italic='1'
    " Set gruvbox to be the default colorscheme
    autocmd vimenter * ++nested colorscheme gruvbox
    " Setting dark mode
    set background=dark


" set
  set scrolloff=4
  set noswapfile
  set nocompatible
  set noshowmode
  set mouse:a
  set shiftwidth=2
  set expandtab
  set tags=tags
  filetype plugin indent on
  filetype plugin on
  set number relativenumber
  set cursorline
  set showtabline=1
  set linebreak
  set showcmd
  set path+=**
  set wildmenu
  set splitbelow splitright
  " set nowrap
  " search
  set hlsearch
  set incsearch
  set ignorecase
  set smartcase
  " set shell to zsh
  set shell=/usr/bin/zsh


" map
  nnoremap Y y$
  nnoremap Q o<esc>
  vmap < <gv
  vmap > >gv
  nnoremap <leader>v :w<cr>:vertical term<cr>
  nnoremap <leader>b :w<cr>:term<cr>
  nnoremap <leader>w <C-w>w
  nnoremap <leader>h :nohl<cr>
  nnoremap <leader><leader> :call NumberToggle()<CR>
  nnoremap <leader>d :YcmCompleter GoToDefinition<CR>
  nnoremap <leader>r :YcmCompleter RefactorRename<Space>
  " Relative or absolute number lines
  function! NumberToggle()
     if &relativenumber

           set norelativenumber

      else

           set relativenumber

         endif
    endfunction


" autocmd
  " only the focused window shows the cursorline
   autocmd WinEnter * setlocal cursorline
   autocmd WinLeave * setlocal nocursorline
   " automatically trim all trailing whiteapaces on save
   autocmd BufWritePre * :%s/\s\+$//e


" other
  " undo break points
    inoremap , ,<c-g>u
    inoremap . .<c-g>u
    inoremap ! !<c-g>u
    inoremap ? ?<c-g>u

  " Jumplist mutations
    nnoremap <expr> k (v:count > 5 ? "m'" . v:count : "") . 'k'
    nnoremap <expr> j (v:count > 5 ? "m'" . v:count : "") . 'j'

  " netrw
    let g:netrw_keepdir = 0
    let g:netrw_winsize = 17
    let g:netrw_banner = 0
    hi! link netrwMarkFile Search

" type :todo to show todo and fixme list
command Todo noautocmd vimgrep /TODO\|FIXME/j ** | cw
