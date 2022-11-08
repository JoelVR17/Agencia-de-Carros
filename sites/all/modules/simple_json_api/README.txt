#####################################################
################# Simple JSON API ###################
#####################################################

***** It is assumed that your site is protected by SSL if not, use at your own risk *****

  ==> SETUP <==

### IMPORTANT! ###
 -- please make sure that theme debug is disabled in your /sites/default/settings.php file
    ex. # $conf['theme_debug'] = FALSE;

1. Install and enable the module as usual.

2. IMPORTANT! navigate to /sites/all/modules/simple_json_api/auth/ and make sure that the file "authfile.csv" is writable by your webserver
   2a. The authfile.csv file is used to check API user permisisions without having to make a database call. ex: "CHMOD 775 authfile.csv" 

3. Clear all caches preferably using 'drush cc all'

4. This module creates two user roles, "Access Simple JSON API" and "Full Access Simple JSON API", and has two permissions.
	to maximize access control and security it is reccomended that the following setup steps be taken
		1.) read this page 
		2.) navigate to http:yoursitename.com/admin/people/permissions and set up the permissions and the roles as follows:


		anonymous user	authenticated user	administrator	Access Simple JSON API	Full Access Simple JSON API
___________________________________________________________________________________________________________________________

Access Simple JSON API					     X			X
___________________________________________________________________________________________________________________________
		
Full Access Simple JSON API				     X			X			X
___________________________________________________________________________________________________________________________


5. once this is done, a user with the "Access Simple JSON API" and "Full Access Simple JSON API" roles assigned will be able to access the api without a time limit.

6. a user with the the "Access Simple JSON API" role assigned will have to re-authenticate after one hour.

____________________________________________________________________
____________________________________________________________________

This module creates 8 endpoints which return data in JSON format and are accessable via a GET or POST request.
NOTE that %username% should be the Drupal user's name who has the assigned one of the roles mentioned in #4 above.  

1. https://sitename.com/api/login/USERNAME -- Drupal USERNAME can be passed to login to the API
2. https://sitename.com/api/%username%/user/UID -- where the UID is a number like 23
3. https://sitename.com/api/%username%/user/list -- a list of UIDs and user names
4. https://sitename.com/api/%username%/node/list -- a list of nodes with NID, type, title and status
5. https://sitename.com/api/%username%/node/NID -- where the NID is a number like 32 or
6. https://sitename.com/api/%username%/node/0/create -- POST an array of variables to create a new node of any type
7. https://sitename.com/api/%username%/node/NID/update -- POST an array of variables to update a node of any type where the NID is a number like 32
8. https://sitename.com/api/%username%/node/NID/delete -- POST an array of variables to delete a node of any type where the NID is a number like 32

Authentication is simplified: a properly configured user only has to access https://sitename.com/api/login/USERNAME
to be authenticated for one hour. No passwords are needed to authenticate.

After authentication, all API endpoints can be accessed with the username following /api/ in the path path ex.

https://somesite.net/api/testuser/node/42


Here are some examples of how to use the API:

/*

----CREATE A NODE----

$handle = curl_init();

$url = "http://mysite.net/api/username/node/0/create";

$postData = array(
	'title' => 'My New Page',
	'type' => 'page',
	'status' => 1,
	'promote' => 0,
	'comment' => 1,
	'body[und][0][value]' => 'Place some interesting text into the body of the new node.',
);

curl_setopt_array($handle, array(
	CURLOPT_URL => $url,
	CURLOPT_POST => TRUE,
	CURLOPT_POSTFIELDS => $postData,
	CURLOPT_RETURNTRANSFER => TRUE,
	)
);

$data = curl_exec($handle);

curl_close($handle);

echo $data;


----UPDATE A NODE----

$handle = curl_init();

$url = "https://mysite.net/api/username/node/57/update";

$postData = array(
	'nid' => '57',
	'body[und][0][value]' => 'Place some other even more interesting text into the body of the node.',
);

curl_setopt_array($handle, array(
	CURLOPT_URL => $url,
	CURLOPT_POST => TRUE,
	CURLOPT_POSTFIELDS => $postData,
	CURLOPT_RETURNTRANSFER => TRUE,
	)
);

$data = curl_exec($handle);

curl_close($handle);

echo $data;



----DELETE A NODE----

$handle = curl_init();

$url = "https://mysite.net/api/username/node/57/delete";

$postData = array(
	'nid' => '57',
);

curl_setopt_array($handle, array(
	CURLOPT_URL => $url,
	// Enable the post response.
	CURLOPT_POST => true,
	// The data to transfer with the response.
	CURLOPT_POSTFIELDS => $postData,
	CURLOPT_RETURNTRANSFER => true,
	)
);

$data = curl_exec($handle);

curl_close($handle);

echo $data;

*/


