# Sistema de Gerenciamento de Acervo

Este projeto implementa em C um sistema para **gerenciar exemplares de uma biblioteca** (livros, artigos, documentos, etc.), utilizando **Tabela Hash** como base para armazenamento e busca rápida.

O objetivo é oferecer uma forma eficiente de **cadastrar, remover, listar e buscar exemplares** por meio de seu **código identificador**.


## Funcionalidades

- **Inserir exemplar** com código, título, autor e área de conhecimento.  
- **Remover exemplar** pelo código.  
- **Buscar exemplar** e exibir seus detalhes completos.  
- **Listar todos os exemplares** presentes no acervo.  
- Menu interativo no terminal para facilitar a navegação.  


## Conceitos Abordados

- Espalhamento Aberto em Tabelas Hash (Open Addressing): diferente de usar encadeamento, aqui o sistema resolve colisões procurando a próxima posição livre dentro da tabela. Esse método garante simplicidade na estrutura e eficiência na busca.
