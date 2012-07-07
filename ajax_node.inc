<?php

function ajax_node_response($div_id, $nid, $type = 'ajax')
{
  if ($type == 'ajax')
  {
    $node = node_load($nid, NULL, false);

    if ($node)
    {
      $vnode = node_view($node);
      $vnode['is_ajax'] = true;
      $output = '<div id="'.$div_id.'">'.theme("node", $vnode).'</div>';
      $commands = array();
      $commands[] = ajax_command_replace('#'.$div_id, $output);
      $page = array('#type' => 'ajax', '#commands' => $commands);
      ajax_deliver($page);
    }

  }
  else
  {
    $output = t("This is some content delivered via a page load.");
    return $output;
  }
}
